/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:56:16 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/28 21:38:14 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_threads(t_table *table)
{
	if (table->must_eat_count)
		if (pthread_create(&table->fullness_thread, NULL,
				fullness_check, table) != 0)
			return ;
	if (pthread_create(&table->death_thread, NULL, death, table) != 0)
		return ;
}
