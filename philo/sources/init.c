/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:07:49 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/05 21:11:07 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int    init_philo(t_arg *arg)
{
	int i;

	i = 0;
	arg->philos = malloc(sizeof(t_philo) * arg->number_of_philosophers);
	if (!arg->philos)
		return(p_error(ERROR_MALLOC), 0);
	while (i < arg->number_of_philosophers)
	{
		arg->philos[i].id = i + 1;
		arg->philos[i].left_fork = i;
		arg->philos[i].right_fork = (i + 1) % arg->number_of_philosophers;
		arg->philos[i].nb_eat = 0;
		arg->philos[i].last_meal_time = 0;
		arg->philos[i].arg = arg;
		i++;
	}
	return (1);
}

int	init_mutex(t_arg *arg)
{
	int	i;

	i = -1;
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->number_of_philosophers);
	if (!arg->forks)
		return (p_error(ERROR_MALLOC), 0);
	while (++i < arg->number_of_philosophers)
	{
		if (pthread_mutex_init(&arg->forks[i], NULL))
			return (destroy_fork(arg, i), 0);
	}
	if (pthread_mutex_init(&(arg->philo_status), NULL))
		return (destroy_fork(arg, arg->number_of_philosophers), 0);
	return (1);
}

int	check_arg(t_arg *arg)
{
	if (arg->number_of_philosophers < 0 || arg->time_to_die < 0 || arg->time_to_eat < 0 || arg->time_to_sleep < 0)
		return (0);
	return (1);
}

int init_arg(int argc, char **argv, t_arg *arg)
{
	if (argc == 5 || argc == 6)
	{
		if (argc == 6)
		{
			if (!ft_atoi(argv[5]))
				return (printf("kek\n"), 0);
			else	
				arg->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		}
		else
			arg->number_of_times_each_philosopher_must_eat = -1;
		arg->number_of_philosophers = ft_atoi(argv[1]);
		arg->time_to_die = ft_atoi(argv[2]); 
		arg->time_to_eat = ft_atoi(argv[3]); 
		arg->time_to_sleep = ft_atoi(argv[4]);
		arg->start_simulation = get_current_time();
		arg->dead = 0;
		if (!check_arg(arg))
			return (0);
		if (!init_mutex(arg))
			return (0);
		return (1);
	}
	return (0);
}
