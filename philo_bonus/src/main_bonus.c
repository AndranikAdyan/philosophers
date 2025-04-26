/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:39:58 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/26 18:54:23 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int argc, char *argv[])
{
	t_table	*table;
	int		status;

	if (!validation(argc, argv))
		return (1);
	table = init_table(argc, argv);
	create_philos(table);
	while (waitpid(-1, &status, 0) != -1)
		;
	free_table(table);
	return 0;
}
