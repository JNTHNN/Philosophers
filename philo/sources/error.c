/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:46:23 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/19 12:42:58 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	p_error(int error_code, t_arg *arg)
{
	(void)arg;
	if (error_code == ERROR_ARG)
		write(2, P_ERROR_ARG, 28);
	if (error_code == ERROR_MALLOC)
		write(2, P_ERROR_MALLOC, 25);
	if (error_code == ERROR_PHILO)
		write(2, P_ERROR_PHILO, 29);
	if (error_code == ERROR_THREAD)
		write(2, P_ERROR_THREAD, 32);
	if (error_code == ERROR_WAIT)
		write(2, P_ERROR_WAIT, 30);
	if (error_code == ERROR_CLEAN)
		write(2, P_ERROR_CLEAN, 27);
	cleaning(arg, error_code);
	return (1);
}
