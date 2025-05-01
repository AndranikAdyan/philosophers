/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:24:16 by aadyan            #+#    #+#             */
/*   Updated: 2025/05/01 20:19:10 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_table *table)
{
	int	index;

	index = 0;
	while (index < table->num_of_philos)
	{
		pthread_create(&table->philos[index].thread, NULL, \
					life, &table->philos[index]);
		++index;
	}
	pthread_create(&table->death_thread, NULL, death, table);
	if (table->must_eat_count)
		pthread_create(&table->fullnes_thread, NULL, philos_fullness, table);
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
	pthread_join(table->death_thread, NULL);
	if (table->must_eat_count)
		pthread_join(table->fullnes_thread, NULL);
}
