/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:25:41 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/08 01:17:51 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_starving(t_arg *arg, t_philo *philo)
{
	if (arg->time_to_die < arg->start_simulation - philo->last_meal_time)
	{
		pthread_mutex_lock(&arg->philo_status);
		write_status(philo->id, DEAD, arg);
		arg->run = 0;
		pthread_mutex_unlock(&arg->philo_status);
	}
}

void	philo_dinner_end(t_arg *arg)
{
	int		i;
	t_philo	philo;

	i = 0;
	while (i < arg->number_of_philosophers)
	{
		philo = arg->philos[i];
		if (philo.nb_eat < arg->nb_eat_limit)
			return ;
		i++;
	}
	pthread_mutex_lock(&arg->philo_status);
	arg->run = 0;
	pthread_mutex_unlock(&arg->philo_status);
}

void	philo_dead(t_arg *arg)
{
	int		i;

	while (arg->run)
	{
		i = 0;
		ft_usleep(100);
		while (arg->run && i < arg->number_of_philosophers)
		{
			pthread_mutex_lock(&arg->dead);
			philo_starving(arg, &arg->philos[i]);
			pthread_mutex_unlock(&arg->dead);
			i++;
		}
		if (arg->nb_eat_limit > 0)
		{
			pthread_mutex_lock(&arg->dead);
			philo_dinner_end(arg);
			pthread_mutex_unlock(&arg->dead);
		}
	}
}
