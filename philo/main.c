 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:28:37 by jgasparo          #+#    #+#             */
/*   Updated: 2024/01/25 15:29:40 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

int	main(int argc, char **argv)
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	
	if (argc == 5 || argc == 6)
	{
		if (argc == 6)
			number_of_times_each_philosopher_must_eat = argv[5];
		number_of_philosophers = argv[1];
		time_to_die = argv[2];
		time_to_eat = argv[3];
		time_to_sleep = argv[4];
	}
}
