/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:12:13 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/23 19:39:16 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	num_range(char *str)
{
	int		i;
	int		len;

	i = 0;
	while (str[i] == 0)
		i++;
	len = 0;
	while (str[i++])
	{
		len++;
		if (len > 11)
			return (0);
	}
	if (ft_atol(str) >= 1 && ft_atol(str) <= INT_MAX)
		return (1);
	return (0);
}

static int	ft_isdigit(int ch)
{
	return (ch >= '0' && ch <= '9');
}

static int	check_symbols(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' '
					&& av[i][j] != '+' && av[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validation(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Incorrect number of arguments\n");
		return (0);
	}
	if (!check_symbols(argc, argv))
	{
		printf("Error: Invalid symbols detected\n");
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		if (!num_range(argv[i]))
		{
			printf("Error: Argument out of range (1 - %d)\n", INT_MAX);
			return (0);
		}
		++i;
	}
	return (1);
}
