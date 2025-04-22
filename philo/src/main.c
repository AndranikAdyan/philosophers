/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:17:04 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/23 02:12:38 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!validation(argc, argv))
		return (1);
	table = init_table(argc, argv);
	init_philo(table);
	create_threads(table);
	join_threads(table);
	free_table(table);
	return (0);
}
