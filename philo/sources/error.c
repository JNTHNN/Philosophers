/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:46:23 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/11 18:07:18 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	p_error(int error_code, t_arg *arg)
{
	if (error_code == ERROR_ARG)
		printf(P_ERROR_ARG);
	if (error_code == ERROR_MALLOC)
		printf(P_ERROR_MALLOC);
	if (error_code == ERROR_PHILO)
		printf(P_ERROR_PHILO);
	if (error_code == ERROR_THREAD)
		printf(P_ERROR_THREAD);
	if (error_code == ERROR_WAIT)
		printf(P_ERROR_WAIT);
	if (error_code == ERROR_CLEAN)
		printf(P_ERROR_CLEAN);
	// if (arg->forks)
	// 	destroy_fork(arg, arg->number_of_philosophers);
	// if (arg->philos)
	// 	free(arg->philos);
	cleaning(arg);
	return (1);
}
