/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:31:55 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/28 21:32:51 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	life(t_philo *philo)
{
	pthread_create(&philo->philo_death_thread, NULL, check_death, philo);
	while (1)
	{
		sem_wait(philo->last_eat_sem);
		philo->last_eat_time = get_time_in_ms();
		sem_post(philo->last_eat_sem);
		philo_pick_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	pthread_join(philo->philo_death_thread, NULL);
}
