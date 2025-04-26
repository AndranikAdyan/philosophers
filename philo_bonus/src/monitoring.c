/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:00:13 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/26 19:33:32 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_fullness(t_philo *philo)
{
	if (philo->table->must_eat_count != 0
		&& philo->eat_count == philo->table->must_eat_count)
	{
		printf("[%lld] %d %s\n", get_time_in_ms() - \
				philo->table->start_time, philo->index, "is fullness");
		free_table(philo->table);
		exit(0);
	}
}
