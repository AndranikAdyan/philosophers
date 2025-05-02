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
	sem_wait(philo->table->forks);
	print_state(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	print_state(philo, "is eating");
	usleep(philo->table->time_to_eat * 1000);
	if (philo->table->must_eat_count
		&& ++philo->eat_count == philo->table->must_eat_count)
		sem_post(philo->table->fullness);
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
	sem_post(philo->table->secure_forks);
	sem_wait(philo->last_eat_sem);
	philo->last_eat_time = get_time_in_ms();
	sem_post(philo->last_eat_sem);
}

void	philo_sleep(t_philo *philo)
{
	print_state(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	print_state(philo, "is thinking");
}
