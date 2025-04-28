/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:06:08 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/29 00:40:09 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_state(t_philo	*philo, char *str)
{
	pthread_mutex_lock(&philo->table->stop_mutex);
	if (!philo->table->stop_program)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		pthread_mutex_unlock(&philo->table->stop_mutex);
		printf("[%lld] %d %s\n", get_time_in_ms() - \
				philo->table->start_time, philo->index, str);
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	else
		pthread_mutex_unlock(&philo->table->stop_mutex);
}

void	philo_pick_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->right);
		print_state(philo, "has taken a right fork");
		pthread_mutex_lock(philo->left);
		print_state(philo, "has taken a left fork");
	}
	else
	{
		pthread_mutex_lock(philo->left);
		print_state(philo, "has taken a left fork");
		if (philo->table->num_of_philos == 1)
		{
			pthread_mutex_unlock(philo->left);
			usleep((philo->table->time_to_die + 1) * 1000);
			return ;
		}
		pthread_mutex_lock(philo->right);
		print_state(philo, "has taken a right fork");
	}
}

void	philo_eat(t_philo *philo)
{
	print_state(philo, "is eating");
	check_usleep(philo, philo->table->time_to_eat * 1000);
	if (philo->table->num_of_philos == 1)
		return ;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_lock(&philo->last_eat_time_mutex);
	philo->last_eat_time = get_time_in_ms();
	pthread_mutex_unlock(&philo->last_eat_time_mutex);
	pthread_mutex_lock(&philo->table->eat_mutex);
	if (philo->table->must_eat_count && ++philo->eat_count == \
			philo->table->must_eat_count)
		philo->table->fullness_count++;
	pthread_mutex_unlock(&philo->table->eat_mutex);
}

void	philo_sleep(t_philo *philo)
{
	print_state(philo, "is sleeping");
	check_usleep(philo, philo->table->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	print_state(philo, "is thinking");
}
