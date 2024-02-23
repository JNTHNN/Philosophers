/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:09:16 by jgasparo          #+#    #+#             */
/*   Updated: 2024/02/23 21:55:32 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	wait_threads(t_philo *philo, t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philosophers)
	{
		if (pthread_join(philo[i].thread_id, NULL) != 0)
		{
			printf("pthread_join error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	create_threads(t_philo *philo, t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread_id, NULL, \
			(void *)philo_routine, &philo[i]))
		{
			printf("pthread_create error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
