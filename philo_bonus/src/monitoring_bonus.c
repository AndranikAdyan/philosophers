/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:41:05 by aadyan            #+#    #+#             */
/*   Updated: 2025/05/03 23:27:23 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*death(void *data)
{
	t_table	*table;
	int		index;

	index = 0;
	table = (t_table *)data;
	sem_wait(table->death);
	while (index < table->num_of_philos)
	{
		kill(table->philo[index].pid, SIGKILL);
		index++;
	}
	sem_post(table->print);
	sem_wait(table->all_dead_sem);
	table->all_dead = 1;
	sem_post(table->all_dead_sem);
	if (table->must_eat_count)
		sem_post(table->fullness);
	return (NULL);
}

void	*fullness_check(void *data)
{
	t_table	*table;
	int		counter;

	counter = 0;
	table = (t_table *)data;
	while (1)
	{
		sem_wait(table->fullness);
		sem_wait(table->all_dead_sem);
		if (table->all_dead)
			return (sem_post(table->all_dead_sem), NULL);
		sem_post(table->all_dead_sem);
		if (++counter == table->num_of_philos)
		{
			sem_wait(table->print);
			sem_post(table->death);
			printf("[%lld] Dinner is over!\n", get_time_in_ms()
				- table->start_time);
			return (NULL);
		}
	}
	return (NULL);
}

void	*check_death(void *data)
{
	t_philo	*philo;

	while (1)
	{
		philo = (t_philo *)data;
		sem_wait(philo->last_eat_sem);
		if (get_time_in_ms() - philo->last_eat_time
			> philo->table->time_to_die)
		{
			sem_wait(philo->table->print);
			sem_post(philo->last_eat_sem);
			printf("[%lld] %d is died\n", get_time_in_ms()
				- philo->table->start_time, philo->index);
			sem_post(philo->table->death);
		}
		else
			sem_post(philo->last_eat_sem);
	}
	return (NULL);
}
