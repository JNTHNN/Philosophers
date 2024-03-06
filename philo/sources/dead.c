/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:25:41 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/06 19:56:54 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_dead(t_arg *arg)
{
	int		i;
	size_t	time;

	while (!arg->is_fed)
	{
		i = -1;
		time = get_current_time();
		while (++i < arg->number_of_philosophers)
		{
			if ((time - arg->philos[i].last_meal_time) > \
				(size_t)arg->time_to_die)
			{
				write_status(i, DEAD, arg);
				arg->dead = 1;
				return ;
			}
		}
		i = 0;
		while (arg->nb_eat_limit != -1 && i < arg->number_of_philosophers \
				&& arg->nb_eat_limit <= (int)arg->philos[i].nb_eat)
			i++;
		if (i == arg->number_of_philosophers)
			arg->is_fed = 1;
	}
	if (arg->is_fed || (int)arg->philos->nb_eat == arg->nb_eat_limit)
		return ;
}
