/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:11:47 by aadyan            #+#    #+#             */
/*   Updated: 2025/05/01 21:46:01 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	init_mutex(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->num_of_philos)
		pthread_mutex_init(&table->forks[index++], NULL);
	pthread_mutex_init(&table->eat_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	pthread_mutex_init(&table->stop_mutex, NULL);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->num_of_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		table->must_eat_count = ft_atol(argv[5]);
	else
		table->must_eat_count = 0;
	table->fullness_count = 0;
	table->stop_program = 0;
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->num_of_philos);
	if (!table->philos)
		return (free(table), NULL);
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->num_of_philos);
	if (!table->forks)
		return (free(table->philos), free(table), NULL);
	init_mutex(table);
	table->start_time = get_time_in_ms();
	return (table);
}

void	init_philo(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->num_of_philos)
	{
		table->philos[index].index = index + 1;
		table->philos[index].eat_count = 0;
		table->philos[index].last_eat_time = table->start_time;
		table->philos[index].left = &table->forks[index];
		table->philos[index].right = &table->forks[(index + 1)
			% table->num_of_philos];
		table->philos[index].table = table;
		pthread_mutex_init(&table->philos[index].last_eat_time_mutex, NULL);
		++index;
	}
}

void	free_table(t_table *table)
{
	int	index;

	pthread_mutex_destroy(&table->eat_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	index = 0;
	while (index < table->num_of_philos)
	{
		pthread_mutex_destroy(&table->forks[index]);
		++index;
	}
	free(table->forks);
	free(table->philos);
	free(table);
}
