/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:27:11 by jgasparo          #+#    #+#             */
/*   Updated: 2024/02/22 20:57:17 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>

typedef	struct s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t left_fork;
	pthread_mutex_t	*right_fork;
	unsigned int 	nb_eat;
	long 			last_meal_time;
}	t_philo;

typedef struct s_arg
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	long	start_simulation;
	t_philo	*philos;
	
}	t_arg;



int	ft_atoi(const char *str);

#endif