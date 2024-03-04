/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_old.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:28:37 by jgasparo          #+#    #+#             */
/*   Updated: 2024/03/04 12:11:05 by jgasparo         ###   ########.fr       */
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

void	thinking(void)
{
	
}

void	sleeping(void)
{
	
}

void	eating(void)
{
	
}

void	*philo_routine(void *t_id)
{
	long	tid;
	
	tid = (long)t_id;
	 // contient la routine des philos
	printf("Ok moi je suis le %li e philo et il est %zu\n", tid, get_current_time());
	
	return (NULL);
}


void	create_thread(t_arg *arg) // passe la fonction philo_routine
{
	// creation des threads par nombre de philo
	long		i;
	pthread_t	*philo;
	
	i = 0;
	philo = malloc(arg->number_of_philosophers * (sizeof(philo)));
	if (!philo)
		exit(printf("error malloc")); // a modifier 
	while (i < arg->number_of_philosophers)
	{
		if (pthread_create(&philo[i], NULL, philo_routine, (void*)i))
			printf("ERROR : IMPOSSIBLE DE CREER LE THREAD %ld", i);
		printf("Creation du thread [%li]\n", (long)philo[i]);
		i++;
	}
	i = 0;
	while (philo[i])
		pthread_join(philo[i++], NULL);
		
}

// void	*init_philo(t_philo *philo, t_arg *arg)
// {
// 	philo->id += 1;
// }

void	write_status(t_philo *philo, char *status, size_t start_time)
{
	printf("%-10zu\t %-10d %s\n", get_current_time() - start_time, philo->id, status);
} // YELLOW "%06ld\t" RST_COL PURPLE "%03d\t" RST_COL CYAN "%s"

void	write_status_id(int i, char *status, size_t start_time)
{
	printf("\e[32m%-10zu\e[0m %-10d %s\n", get_current_time() - start_time, i, status);
}

void	init_arg(t_arg *arg, int argc, char **argv)
{
	// checker que des nb positifs et max 200 (a voir avec atoi)
	if (argc == 5 || argc == 6)
	{
		if (argc == 6)
			arg->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]); 
		arg->number_of_philosophers = ft_atoi(argv[1]);
		arg->time_to_die = ft_atoi(argv[2]); 
		arg->time_to_eat = ft_atoi(argv[3]); 
		arg->time_to_sleep = ft_atoi(argv[4]); 
	}
}

int	main(int argc, char **argv)
{
	t_arg	arg;
	
	if (argc > 0) // check des args ici ou dans init_arg ?
	{
		init_arg(&arg, argc, argv);
		create_thread(&arg);
		
		printf(" nb philo : %d / die : %d / eat : %d / sleep : %d / (opt) nb of meals : %d\n", arg.number_of_philosophers, arg.time_to_die, arg.time_to_eat, arg.time_to_sleep, arg.number_of_times_each_philosopher_must_eat); 	// proteger printf avec mutex
	}
	else
		printf("philo : no arguments");
	return (0);
}

// CREER UN THREAD
// int	pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(start_routine)(void *), void *restrict arg);
// thread = stock l'ID du thread qu'on va creer
// attr = arg permettant de changer les attributs par defaut du new thread 
// start_routine = fonction par laquelle le thread commence son exec. la fonction en param [void *nomfonc(void *arg)]
// arg = pointer vers l'arg a passer dans la fonc start_routine, si plusiers params -> pointer vers struct de data
// valeurs de retour : if succes =  var thread = ID du thread cree et return 0 / if not = code erreur

// RECUPERER UN THREAD OU LE DETACHER
// int pthread_join(pthread_t thread, void **retval)
// thread = ID du thread qu'on attend /!\ DOIT ETRE JOIGNABLE (NON DETACHEE)
// retval = pointer vers var qui peut contenir le return de la fonc routine du thread( la fonction start_routine qu'on a fournie lors de la crea du thread)
// if no need, on peut NULL
// valeurs de retour : if succes = 0 / if not = code erreur


//	DATA RACE
//	2 threads accedent a la meme zone memoire en meme temps, le thread 2 n'attend pas la fin du 1 pour commencer son iteration de la meme donnee par exemple 