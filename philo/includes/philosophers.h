/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:27:11 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/19 15:05:37 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include "define.h"

typedef struct s_arg	t_arg;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	int				left_fork;
	int				right_fork;
	int				nb_eat;
	long			last_meal_time;
	t_arg			*arg;
}	t_philo;

struct s_arg
{
	int				number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nb_eat_limit;
	long			start_simulation;
	int				is_fed;
	pthread_mutex_t	*forks;
	pthread_mutex_t	philo_status;
	pthread_mutex_t	dead;
	t_philo			*philos;
	int				run;
};

typedef enum e_error
{
	ERROR_ARG = -1,
	ERROR_MALLOC = -2,
	ERROR_PHILO = -3,
	ERROR_THREAD = -4,
	ERROR_WAIT = -5,
	ERROR_CLEAN = -6,
}	t_error;

/*			FT_ATOL.C		*/
long	ft_atol(const char *str);

/*			TIME.C			*/
long	get_current_time(long start_time);
void	ft_usleep(size_t milliseconds, t_arg *arg);

/*			THREADS.C		*/
int		wait_threads(t_arg *arg);
int		create_threads(t_arg *arg);

/*			ROUTINE.C		*/
void	*philo_routine(void *philo);

/*			INIT.C			*/
int		init_philo(t_arg *arg);
int		init_arg(int argc, char **argv, t_arg *arg);

/*			WRITE.C			*/
void	write_status(char *str, t_philo *philo);
void	write_one_philo(int id, char *str, t_arg *arg);

/*			ERROR.C			*/
int		p_error(int error_code, t_arg *arg);

/*			DEAD.C			*/
void	philo_dead(t_arg *arg);

/*			CLEAN.C			*/
void	destroy_mutex(t_arg *arg, int nb_forks);
int		cleaning(t_arg *arg, int error);

#endif