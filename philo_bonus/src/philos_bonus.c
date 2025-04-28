/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:29:43 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/28 21:32:02 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philos(t_table *table)
{
	int		index;
	pid_t	pid;

	index = 0;
	table->start_time = get_time_in_ms();
	while (index < table->num_of_philos)
	{
		pid = fork();
		if (pid == 0)
		{
			table->philo[index].pid = pid;
			life(&table->philo[index]);
			pthread_join(table->philo[index].philo_death_thread, NULL);
			exit(0);
		}
		++index;
	}
}
