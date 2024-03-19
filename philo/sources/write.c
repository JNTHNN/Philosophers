/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:09:50 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/19 12:41:32 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	write_status(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->philo_status);
	if (philo->arg->run)
		printf(GREEN "%-10zu" RESET ORANGE "%-10d" RESET YELLOW"%s\n" RESET, \
				get_current_time(philo->arg->start_simulation), philo->id, str);
	pthread_mutex_unlock(&philo->arg->philo_status);
}

void	write_one_philo(int id, char *str, t_arg *arg)
{
	pthread_mutex_lock(&arg->philo_status);
	if (arg->run)
		printf(GREEN "%-10zu" RESET ORANGE "%-10d" RESET YELLOW"%s\n" RESET, \
				get_current_time(arg->start_simulation), id, str);
	pthread_mutex_unlock(&arg->philo_status);
}
