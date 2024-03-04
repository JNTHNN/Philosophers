/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:11:03 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/04 18:55:17 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

void	destroy_fork(t_arg *arg, int nb_forks)
{
	int	i;
	
	i = 0;
	while (i < nb_forks)
	{
		pthread_mutex_destroy(&arg->forks[i]);
		i++;
	}
	free(arg->forks);
}

int	one_philo(t_arg *arg)
{
	write_status(1, FORK, arg);
	ft_usleep(arg->time_to_die);
	write_status(1, DEAD, arg);
	return (0);
}

int main(int argc, char **argv)
{
	t_arg   arg;

	if (!init_arg(argc, argv, &arg))
		return (printf("error arg\n"), 1);
	printf("test\n");
	if (arg.number_of_philosophers == 1)
		return (one_philo(&arg));
	if (!init_philo(&arg))
		return (printf("error init philo\n"), 1);
	printf("test1\n");
	if (!create_threads(&arg))
		return (printf("error create threads\n"), 1);
	printf("test2\n");
	if (!wait_threads(&arg))
		return (printf("error wait threads\n"), 1);
	// if (!cleaning(&arg, philo))
	destroy_fork(&arg, arg.number_of_philosophers);
	free(arg.philos);
	
	
	

	return (0);

}
// printf(" nb philo : %d / die : %d / eat : %d / sleep : %d / (opt) nb of meals : %d\n", arg.number_of_philosophers, arg.time_to_die, arg.time_to_eat, arg.time_to_sleep, arg.number_of_times_each_philosopher_must_eat);