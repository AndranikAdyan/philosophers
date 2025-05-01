/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:30:37 by aadyan            #+#    #+#             */
/*   Updated: 2025/05/01 21:35:28 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	someone_dead(t_table *table, int index)
{
	pthread_mutex_lock(&table->philos[index].last_eat_time_mutex);
	if (get_time_in_ms() - table->philos[index].last_eat_time > \
		table->time_to_die)
	{
		pthread_mutex_unlock(&table->philos[index].last_eat_time_mutex);
		pthread_mutex_lock(&table->stop_mutex);
		table->stop_program = 1;
		pthread_mutex_lock(&table->print_mutex);
		printf("[%lld] %d is dead", get_time_in_ms() - \
			table->start_time, index + 1);
		pthread_mutex_unlock(&table->print_mutex);
		pthread_mutex_unlock(&table->stop_mutex);
		return (1);
	}
	else
		pthread_mutex_unlock(&table->philos[index].last_eat_time_mutex);
	return (0);
}

void	*death(void *data)
{
	int		index;
	t_table	*table;

	table = (t_table *)data;
	while (1)
	{
		index = 0;
		usleep(1000);
		while (index < table->num_of_philos)
		{
			if (someone_dead(table, index))
				return (NULL);
			++index;
			if (table->must_eat_count)
			{
				pthread_mutex_lock(&table->eat_mutex);
				if (table->num_of_philos <= table->fullness_count)
					return (pthread_mutex_unlock(&table->eat_mutex), NULL);
				pthread_mutex_unlock(&table->eat_mutex);
			}
		}
	}
	return (NULL);
}

void	*philos_fullness(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(&table->stop_mutex);
		if (table->stop_program)
			return (pthread_mutex_unlock(&table->stop_mutex), NULL);
		pthread_mutex_lock(&table->eat_mutex);
		if (table->fullness_count == table->num_of_philos)
		{
			table->stop_program = 1;
			pthread_mutex_lock(&table->print_mutex);
			printf("Dinner is over :)\n");
			pthread_mutex_unlock(&table->print_mutex);
			pthread_mutex_unlock(&table->eat_mutex);
		}
		else
			pthread_mutex_unlock(&table->eat_mutex);
		pthread_mutex_unlock(&table->stop_mutex);
	}
	return (NULL);
}
