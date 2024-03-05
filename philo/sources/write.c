/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:09:50 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/05 15:49:52 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    write_status(int id, char *str, t_arg *arg)
{
    pthread_mutex_lock(&arg->philo_status);
    if (!arg->dead)
        printf("\033[1;32m%-10zu\033[0m \033[1;38;5;208m%-10d\033[0m \033[1;33m%s\033[0m\n", get_current_time() - arg->start_simulation, id, str);
    pthread_mutex_unlock(&arg->philo_status);
}