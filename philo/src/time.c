/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:05:08 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/23 17:44:17 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	check_usleep(t_philo *philo, int time)
{
	int	i;

	i = 0;
	while (i <= time)
	{
		pthread_mutex_lock(&philo->table->stop_mutex);
		if (philo->table->stop_program)
		{
			pthread_mutex_unlock(&philo->table->stop_mutex);
			return ;
		}
		else
			pthread_mutex_unlock(&philo->table->stop_mutex);
		usleep(100);
		i += 10;
	}
}
