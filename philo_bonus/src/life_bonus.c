/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:31:55 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/26 19:22:21 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	life(t_philo *philo)
{
	while (1)
	{
		philo_pick_fork(philo);
		philo_eat(philo);
		check_fullness(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}