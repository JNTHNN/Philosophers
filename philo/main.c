/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:11:03 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/18 13:30:44 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

// int	one_philo(t_arg *arg)
// {
// 	write_status(1, FORK, arg);
// 	ft_usleep(arg->time_to_die, arg);
// 	write_status(1, DEAD, arg);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_arg	arg;

	if (!init_arg(argc, argv, &arg))
		return (p_error(ERROR_ARG, &arg));
	// if (arg.number_of_philosophers == 1)
	// 	return (one_philo(&arg));
	if (!init_philo(&arg))
		return (p_error(ERROR_PHILO, &arg));
	if (!create_threads(&arg))
		return (p_error(ERROR_THREAD, &arg));
	// if (!wait_threads(&arg))
	// 	return (p_error(ERROR_WAIT, &arg));
	if (!cleaning(&arg))
		return (p_error(ERROR_CLEAN, &arg));
	return (0);
}
