/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:46:41 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/13 23:17:18 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_fork(t_arg *arg, int nb_forks)
{
	int	i;

	i = 0;
	while (i < nb_forks)
	{
		if (pthread_mutex_destroy(&arg->forks[i]))
			break ;
		i++;
	}
	free(arg->forks);
}

// int	cleaning(t_arg *arg, t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	while (i < arg->number_of_philosophers)
// 	{
// 		pthread_mutex_destroy(&philo[i].left_fork);
// 		pthread_mutex_destroy(&philo[i].right_fork);
// 		i++;
// 	}
// 	return (1);
// }

int	cleaning(t_arg *arg)
{
	if (arg)
	{
		destroy_fork(arg, 0);
		free(arg->philos);
		return (1);
	}
	return (0);
}
