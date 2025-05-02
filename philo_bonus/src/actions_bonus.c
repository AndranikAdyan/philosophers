/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:31:53 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/28 21:30:24 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	print_state(t_philo	*philo, char *str)
{
	sem_wait(philo->table->print);
	printf("[%lld] %d %s\n", get_time_in_ms()
		- philo->table->start_time, philo->index, str);
	sem_post(philo->table->print);
}

void	philo_pick_fork(t_philo *philo)
{
	sem_wait(philo->table->secure_forks);
	sem_wait(philo->table->forks);
	print_state(philo, "has taken a fork");
	if (philo->table->num_of_philos == 1)
	{
		sem_post(philo->table->forks);
		sem_post(philo->table->secure_forks);
		usleep((philo->table->time_to_die + 2) * 1000);
		sem_post(philo->table->death);
	}
	sem_wait(philo->table->forks);
	print_state(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	long long	start_time;

	start_time = get_time_in_ms();
	print_state(philo, "is eating");
	while (get_time_in_ms() - start_time < philo->table->time_to_eat)
		usleep(100);
	sem_wait(philo->last_eat_sem);
	philo->last_eat_time = get_time_in_ms();
	sem_post(philo->last_eat_sem);
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
	sem_post(philo->table->secure_forks);
	if (philo->table->must_eat_count
		&& ++philo->eat_count == philo->table->must_eat_count)
		sem_post(philo->table->fullness);
}

void	philo_sleep(t_philo *philo)
{
	long long	start_time;

	start_time = get_time_in_ms();
	print_state(philo, "is sleeping");
	while (get_time_in_ms() - start_time < philo->table->time_to_sleep)
		usleep(100);
}

void	philo_think(t_philo *philo)
{
	print_state(philo, "is thinking");
}
