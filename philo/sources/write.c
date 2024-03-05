/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:09:50 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/05 20:58:33 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    write_status(int id, char *str, t_arg *arg)
{
    pthread_mutex_lock(&arg->philo_status);
    if (!arg->dead)
        printf(GREEN "%-10zu" RESET ORANGE "%-10d" RESET YELLOW"%s\n" RESET, get_current_time() - arg->start_simulation, id, str);
    pthread_mutex_unlock(&arg->philo_status);
}