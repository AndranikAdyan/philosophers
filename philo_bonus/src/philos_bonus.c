/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:29:43 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/26 18:57:44 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philos(t_table *table)
{
	int		index;
	pid_t	pid;

	index = -1;
	table->start_time = get_time_in_ms();
	while (++index < table->num_of_philos)
	{
		pid = fork();
		if (pid == 0)
			life(&table->philo[index]);
		index++;
	}
}
