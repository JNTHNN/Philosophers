/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:11:03 by jgasparo          #+#    #+#             */
/*   Updated: 2024/02/23 10:28:14 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

size_t	get_current_time(void)
{
	struct timeval	time;
	
	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(milliseconds / 10);
	return (0);
}

void    write_status(t_philo *philo, char *status)
{
    printf("%zu %d %s\n", get_current_time(), philo->id, status);
}

void    philo_routine(t_philo *philo)
{
    while (1)
    {
        write_status(philo, "is thinking");
        ft_usleep(1000);
        write_status(philo, "is eating");
        ft_usleep(1000);
        write_status(philo, "is sleeping");
        ft_usleep(1000);
        if (get_current_time() % 3 == 0)
            break;
    }
    system("leaks philo");
    exit(0);
}
int   wait_threads(t_philo *philo, t_arg *arg)
{
    int i;

    i = 0;
    while (i < arg->number_of_philosophers)
    {
        if (pthread_join(philo[i].thread_id, NULL) != 0)
        {
            printf("pthread_join error\n");
            return (0);
        }
        i++;
    }
    return (1);
}

int    create_threads(t_philo *philo, t_arg *arg)
{
    int i;

    i = 0;
    while (i < arg->number_of_philosophers)
    {
        if (pthread_create(&philo[i].thread_id, NULL, (void *)philo_routine, &philo[i]) != 0)
        {
            printf("pthread_create error\n");
            return (0);
        }
        i++;
    }
    return (1);
}

int    init_philo(t_philo **philo, t_arg *arg)
{
    int i;

    i = 0;
    *philo = malloc(sizeof(t_philo) * arg->number_of_philosophers);
    if (!*philo)
    {
        printf("malloc error\n"); 
        return(0);
    }
    while (i < arg->number_of_philosophers)
    {
        (*philo)[i].id = i + 1;
        (*philo)[i].nb_eat = 0;
        (*philo)[i].last_meal_time = 0;
        i++;
    }
    return (1);
}

int init_arg(int argc, char **argv, t_arg *arg)
{
    if (argc == 5 || argc == 6)
    {
        if (argc == 6)
			arg->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
        else 
            arg->number_of_times_each_philosopher_must_eat = -1;
		arg->number_of_philosophers = ft_atoi(argv[1]);
		arg->time_to_die = ft_atoi(argv[2]); 
		arg->time_to_eat = ft_atoi(argv[3]); 
		arg->time_to_sleep = ft_atoi(argv[4]);
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_arg   arg;
    t_philo *philo;

    if (!init_arg(argc, argv, &arg))
        return (printf("error arg\n"), 1);
    if (!init_philo(&philo, &arg))
        return (printf("error init philo\n"), 1);
    if (!create_threads(philo, &arg))
        return (printf("error create threads\n"), 1);
    if (!wait_threads(philo, &arg))
        return (printf("error wait threads\n"), 1);
    

    return (0);

}
    // printf(" nb philo : %d / die : %d / eat : %d / sleep : %d / (opt) nb of meals : %d\n", arg.number_of_philosophers, arg.time_to_die, arg.time_to_eat, arg.time_to_sleep, arg.number_of_times_each_philosopher_must_eat);