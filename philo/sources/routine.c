/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:30:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/19 13:17:47 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	thinking(t_philo *philo)
{
	write_status(THINK, philo);
}

static void	sleeping(t_philo *philo)
{
	write_status(SLEEP, philo);
	ft_usleep(philo->arg->time_to_sleep, philo->arg);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->forks[philo->left_fork]);
	write_status(FORK, philo);
	pthread_mutex_lock(&philo->arg->forks[philo->right_fork]);
	write_status(FORK, philo);
	pthread_mutex_lock(&philo->arg->dead);
	write_status(EAT, philo);
	philo->last_meal_time = get_current_time(philo->arg->start_simulation);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->arg->dead);
	ft_usleep(philo->arg->time_to_eat, philo->arg);
	pthread_mutex_unlock(&philo->arg->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->arg->forks[philo->right_fork]);
}

void	*philo_routine(void *p_arg)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = (t_philo *)p_arg;
	arg = philo->arg;
	philo->last_meal_time = arg->start_simulation;
	if (philo->id % 2)
		ft_usleep(50, arg);
	while (19)
	{
		pthread_mutex_lock(&arg->philo_status);
		if (!philo->arg->run)
			break ;
		pthread_mutex_unlock(&arg->philo_status);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	pthread_mutex_unlock(&arg->philo_status);
	return (NULL);
}
