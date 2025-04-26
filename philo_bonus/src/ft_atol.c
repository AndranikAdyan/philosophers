/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:30:30 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/26 18:41:24 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	ft_atol(char *num)
{
	long int	res;
	int			sign;
	int			i;

	sign = 1;
	res = 0;
	i = 0;
	if (num[i] == '-' || num[i] == '+')
		if (num[i++] == '-')
			sign = -1;
	while (num[i] == '0')
		i++;
	while (num[i])
		res = (res + num[i++] - '0') * 10;
	return (sign * res / 10);
}
