/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:39:58 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/27 23:51:30 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_table		*table;

	if (!validation(argc, argv))
		return (1);
	table = init_table(argc, argv);
	create_philos(table);
	create_threads(table);
	if (table->must_eat_count)
		pthread_join(table->fullness_thread, NULL);
	pthread_join(table->death_thread, NULL);
	free_table(table);
	return (0);
}
