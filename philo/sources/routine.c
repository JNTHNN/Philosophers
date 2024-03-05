/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:30:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/05 16:24:16 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eating(int id, t_philo *philo)
{
	t_arg	*arg;

	arg = philo->arg;
	pthread_mutex_lock(&(arg->forks[philo->left_fork]));
	write_status(philo->id, FORK, arg);
	pthread_mutex_lock(&(arg->forks[philo->right_fork]));
	write_status(philo->id, FORK, arg);
	write_status(philo->id, EAT, arg);
	arg->philos[id].last_meal_time = get_current_time();
	(philo->nb_eat)++;
	ft_usleep(arg->time_to_eat);
	pthread_mutex_unlock(&(arg->forks[philo->left_fork]));
	pthread_mutex_unlock(&(arg->forks[philo->right_fork]));

	
}

void	thinking(t_arg *arg, t_philo *philo)
{
	write_status(philo->id, THINK, arg);
}

void	sleeping(t_arg *arg, t_philo *philo)
{
	write_status(philo->id, SLEEP, arg);
	ft_usleep(arg->time_to_sleep);
}

void	philo_routine(void *p_arg)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = (t_philo *)p_arg;
	arg = philo->arg;
	philo->last_meal_time = arg->start_simulation;
	if (philo->id % 2)
		ft_usleep(10);
	while (arg->dead != 1)
	{
		thinking(arg, philo);
		eating(philo->id, philo);
		if (arg->full_eat|| (int)arg->philos->nb_eat == arg->number_of_times_each_philosopher_must_eat)
			break ;
		sleeping(arg, philo);
		thinking(arg, philo);
	}
	// return (NULL);
}
