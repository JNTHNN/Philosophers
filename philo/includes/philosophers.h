/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:27:11 by jgasparo          #+#    #+#             */
/*   Updated: 2024/02/16 11:12:46 by jgasparo         ###   ########.fr       */
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

typedef struct s_arg
{
	int	number_of_philosophers;  // = nb of forks cuz 1 philo = 1 fork
	int	time_to_die; // in milliseconds , if philo doesnt eat after his last meals or begin = DIE
	int	time_to_eat; // in milliseconds, time to eat for a philo
	int	time_to_sleep; // in milliseconds, time to sleep for a philo
	int	number_of_times_each_philosopher_must_eat; // nb of meals (optional)
}	t_arg;

typedef	struct s_philo
{
	int				id;
	int 			left_fork;
	int				right_fork;
	t_arg			*arg; // time eat die sleep must eat
	unsigned int 	nb_eat;
}	t_philo;


int	ft_atoi(const char *str);

#endif