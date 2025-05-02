/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:29:43 by aadyan            #+#    #+#             */
/*   Updated: 2025/05/01 21:58:28 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_philos(t_table *table)
{
	int		index;

	index = 0;
	while (index < table->num_of_philos)
	{
		table->philo[index].pid = fork();
		if (table->philo[index].pid == 0)
			life(&table->philo[index]);
		++index;
	}
}
