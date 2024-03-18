/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:05:12 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/18 15:53:19 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	get_current_time(long start_time)
{
	struct timeval	time;
	long			time_ms;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	time_ms =  (time.tv_sec * 1000) + (time.tv_usec / 1000) - start_time;
	return (time_ms);
}

void	ft_usleep(unsigned long duration, t_arg *arg)
{
	unsigned long	start;

	start = get_current_time(0);
	while (19)
	{
		if (get_current_time(0) - start >= duration)
			break ;
		pthread_mutex_lock(&arg->philo_status);
		if (!arg->run)
		{
			pthread_mutex_unlock(&arg->philo_status);
			break ;
		}
		pthread_mutex_unlock(&arg->philo_status);
		usleep(duration / 10);
	}
}

// int	ft_usleep(size_t milliseconds)
// {
// 	size_t	start;

// 	start = get_current_time();
// 	while ((get_current_time() - start) < milliseconds)
// 		usleep(milliseconds / 10);
// 	return (0);
// }
