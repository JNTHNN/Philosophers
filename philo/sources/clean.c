/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:46:41 by jgasparo          #+#    #+#             */
/*   Updated: 2024/02/29 17:55:09 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int cleaning(t_arg *arg, t_philo *philo)
{
    int i;

    i = 0;
    while (i < arg->number_of_philosophers)
    {
        pthread_mutex_destroy(&(*philo)[i].left_fork);
        pthread_mutex_destroy(&(*philo)[i].right_fork);
        i++;
    }
    return(1);    
}