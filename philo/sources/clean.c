/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:46:41 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/19 12:42:22 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_mutex(t_arg *arg, int nb_forks)
{
	int	i;

	i = 0;
	if (arg->forks)
	{
		while (i < nb_forks)
		{
			if (pthread_mutex_destroy(&arg->forks[i]))
				break ;
			i++;
		}
	}
	if (pthread_mutex_destroy(&arg->philo_status))
		return ;
	if (pthread_mutex_destroy(&arg->dead))
		return ;
	free(arg->forks);
}

int	cleaning(t_arg *arg, int error)
{
	if (arg)
	{
		if (error != ERROR_ARG)
			destroy_mutex(arg, arg->number_of_philosophers);
		free(arg->philos);
		return (1);
	}
	return (0);
}
