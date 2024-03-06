/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:46:23 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/06 17:37:13 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	p_error(int error_code)
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
	return (1);
}
