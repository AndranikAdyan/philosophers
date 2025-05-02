/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:26:27 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/28 21:29:36 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_philo(t_table *table)
{
	int		index;
	char	*sem_name;

	index = 0;
	while (index < table->num_of_philos)
	{
		table->philo[index].index = index + 1;
		table->philo[index].eat_count = 0;
		table->philo[index].table = table;
		table->philo[index].last_eat_time = table->start_time;
		sem_name = ft_itoa(index);
		sem_unlink(sem_name);
		table->philo[index].last_eat_sem
			= sem_open(sem_name, O_CREAT | O_EXCL, 0644, 1);
		free(sem_name);
		++index;
	}
}

static void	init_sems(t_table *table)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/secure_forks");
	sem_unlink("/fullness");
	sem_unlink("/death");
	table->forks = sem_open("/forks", O_CREAT | O_EXCL,
			0644, table->num_of_philos);
	table->secure_forks = sem_open("/secure_forks", O_CREAT | O_EXCL,
			0644, table->num_of_philos / 2);
	table->print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	table->fullness = sem_open("/fullness", O_CREAT | O_EXCL, 0644, 0);
	table->death = sem_open("/death", O_CREAT | O_EXCL, 0644, 0);
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
	table->philo = malloc(sizeof(t_philo) * table->num_of_philos);
	init_sems(table);
	table->start_time = get_time_in_ms();
	init_philo(table);
	return (table);
}

static void	free_sems(t_table *table)
{
	int		index;
	char	*sem_name;

	index = 0;
	while (index < table->num_of_philos)
	{
		sem_close(table->philo[index].last_eat_sem);
		sem_name = ft_itoa(index);
		sem_unlink(sem_name);
		free(sem_name);
		++index;
	}
	sem_close(table->forks);
	sem_unlink("/forks");
	sem_close(table->secure_forks);
	sem_unlink("/secure_forks");
	sem_close(table->print);
	sem_unlink("/print");
}

void	free_table(t_table *table)
{
	free_sems(table);
	free(table->philo);
	free(table);
}
