/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:30:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/18 15:40:33 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	thinking(t_arg *arg, t_philo *philo)
{
	(void)arg;
	// write_status(philo->id, THINK, arg);
	write_status(THINK, philo);
}

void	sleeping(t_arg *arg, t_philo *philo)
{
	// write_status(philo->id, SLEEP, arg);
	write_status(SLEEP, philo);
	ft_usleep(arg->time_to_sleep, arg);
}
void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->forks[philo->left_fork]);
	// write_status(philo->id, FORK, philo->arg);
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
	sleeping(philo->arg,philo);
	// ft_print_log(philo, "is sleeping");
	ft_usleep(philo->arg->time_to_sleep, philo->arg);
	// ft_print_log(philo, "is thinking");
	thinking(philo->arg, philo);
}

// void	eating(int id, t_philo *philo)
// {
// 	t_arg	*arg;
// 	(void)id;

// 	arg = philo->arg;
// 	pthread_mutex_lock(&(arg->forks[philo->left_fork]));
// 	// write_status(philo->id, FORK, arg);
// 	write_status(FORK, philo);
// 	pthread_mutex_lock(&(arg->forks[philo->right_fork]));
// 	// write_status(philo->id, FORK, arg);
// 	write_status(FORK, philo);
// 	pthread_mutex_lock(&philo->arg->dead);
// 	// write_status(philo->id, EAT, arg);
// 	write_status(EAT, philo);
// 	// arg->philos[id].last_meal_time = get_current_time(philo->arg->start_simulation);
// 	arg->philos->last_meal_time = get_current_time(philo->arg->start_simulation);
// 	philo->nb_eat++;
// 	pthread_mutex_unlock(&philo->arg->dead);
// 	ft_usleep(philo->arg->time_to_eat, philo->arg);
// 	pthread_mutex_unlock(&philo->arg->forks[philo->left_fork]);
// 	pthread_mutex_unlock(&philo->arg->forks[philo->right_fork]);
// }


// void	*philo_routine(t_philo *philo)
// {
// 	if (philo->id)
// 		ft_usleep(50, philo->arg);
// 	while (19)
// 	{
// 		pthread_mutex_lock(&philo->arg->philo_status);
// 		if (!philo->arg->run)
// 			break ;
// 		pthread_mutex_unlock(&philo->arg->philo_status);
// 		eating(philo->id, philo);
// 		sleeping(philo->arg, philo);
// 		thinking(philo->arg, philo);
// 	}
// 	pthread_mutex_unlock(&philo->arg->philo_status);
// 	return (NULL);
	
// }

void	*philo_routine(void *p_arg)
{
	t_arg	*arg;
	t_philo	*philo;

	philo = (t_philo *)p_arg;
	arg = philo->arg;
	// philo->last_meal_time = arg->start_simulation;
	if (philo->id % 2)
		ft_usleep(50, arg);
	while (19)
	{
		pthread_mutex_lock(&arg->philo_status);
		if (!philo->arg->run)
			break ;
		pthread_mutex_unlock(&arg->philo_status);
		thinking(arg, philo);
		// eating(philo->id, philo);
		eating(philo);
		sleeping(arg, philo);
		// thinking(arg, philo); // a voir pour enlever
	}
	pthread_mutex_unlock(&arg->philo_status);
	return (NULL);
}
