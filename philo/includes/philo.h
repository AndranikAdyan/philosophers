/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:54:49 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/23 18:24:00 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int					num_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_count;
	int					fullness_count;
	int					stop_program;
	long long			start_time;
	pthread_mutex_t		stop_mutex;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		*forks;
	pthread_t			death_thread;
	pthread_t			fullnes_thread;
	t_philo				*philos;
}	t_table;

struct s_philo
{
	int					index;
	int					eat_count;
	long long			last_eat_time;
	pthread_mutex_t		*left;
	pthread_mutex_t		*right;
	pthread_mutex_t		last_eat_time_mutex;
	pthread_t			thread;
	t_table				*table;
};

int					validation(int argc, char **argv);
long int			ft_atol(char *num);

long long			get_time_in_ms(void);
void				check_usleep(t_philo *philo, int time);

t_table				*init_table(int argc, char **argv);
void				init_philo(t_table *table);
void				free_table(t_table *table);

void				join_threads(t_table *table);
void				create_threads(t_table *table);

void				*life(void *table);

void				philo_pick_fork(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_think(t_philo *philo);

void				*death(void *data);
void				*philos_fullness(void *data);

#endif