/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:24:16 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/23 02:12:44 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->num_of_philos)
	{
		pthread_create(&table->philos[index].thread, NULL, life, NULL);
		++index;
	}
}

void	join_threads(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->num_of_philos)
	{
		pthread_join(table->philos[index].thread, NULL);
		++index;
	}
}
