/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:12:42 by aadyan            #+#    #+#             */
/*   Updated: 2025/05/03 23:10:31 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_count;
	int			all_dead;
	long long	start_time;
	sem_t		*secure_forks;
	sem_t		*forks;
	sem_t		*print;
	sem_t		*fullness;
	sem_t		*death;
	sem_t		*all_dead_sem;
	pthread_t	fullness_thread;
	pthread_t	death_thread;
	t_philo		*philo;
}	t_table;

typedef struct s_philo
{
	int			index;
	int			eat_count;
	long long	last_eat_time;
	pthread_t	philo_death_thread;
	pid_t		pid;
	sem_t		*last_eat_sem;
	t_table		*table;
}	t_philo;

long int	ft_atol(char *num);
char		*ft_itoa(int nb);

int			validation(int argc, char **argv);

long long	get_time_in_ms(void);
void		check_usleep(long long t);

t_table		*init_table(int argc, char **argv);
void		free_table(t_table *table);

void		life(t_philo *philo);

void		philo_pick_fork(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

void		create_philos(t_table *table);

void		*fullness_check(void *data);
void		*check_death(void *data);
void		*death(void *data);
void		create_threads(t_table *table);

#endif
