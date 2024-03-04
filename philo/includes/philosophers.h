/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:27:11 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/04 12:39:34 by jgasparo         ###   ########.fr       */
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
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DEAD "died"

typedef struct s_arg	t_arg;

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	int				left_fork;
	int				right_fork;
	unsigned int	nb_eat;
	long			last_meal_time;
	t_arg			*arg;
}	t_philo;

struct s_arg
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	long	start_simulation;
	int		dead;
	int		full_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t philo_status;
	t_philo	*philos;
};

int		ft_atoi(const char *str);
void	destroy_fork(t_arg *arg, int nb_forks);

/*	TIME.C	*/
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);

/*	THREADS.C	*/
int		wait_threads(t_arg *arg);
int		create_threads(t_arg *arg);

/*	ROUTINE.C	*/
void	philo_routine(void *philo);

/*	INIT.C	*/
int	init_philo(t_arg *arg);
int	init_fork(t_arg *arg);
int	init_arg(int argc, char **argv, t_arg *arg);

/*	WRITE.C	*/
void	write_status(int id, char *str, t_arg *arg);

#endif