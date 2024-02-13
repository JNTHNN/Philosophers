/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:28:37 by jgasparo          #+#    #+#             */
/*   Updated: 2024/02/13 19:51:28 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

void	init_arg(t_arg *arg, int argc, char **argv)
{
	// checker que des nb positifs
	if (argc == 5 || argc == 6)
	{
		if (argc == 6)
			arg->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]); // nb of meals (optional)
		arg->number_of_philosophers = ft_atoi(argv[1]); // = nb of forks cuz 1 philo = 1 fork
		arg->time_to_die = ft_atoi(argv[2]); // in milliseconds , if philo doesnt eat after his last meals or begin = DIE
		arg->time_to_eat = ft_atoi(argv[3]); // in milliseconds, time to eat for a philo
		arg->time_to_sleep = ft_atoi(argv[4]); // in milliseconds, time to sleep for a philo
	}
}

int	main(int argc, char **argv)
{
	t_arg	arg;
	
	if (argc > 0) // check des args ici ou dans init_arg ?
	{
		init_arg(&arg, argc, argv);
		
		printf(" nb philo : %d / die : %d / eat : %d / sleep : %d / (opt) nb of meals : %d\n", arg.number_of_philosophers, arg.time_to_die, arg.time_to_eat, arg.time_to_sleep, arg.number_of_times_each_philosopher_must_eat); 	// proteger printf avec mutex
	}
	else
		printf("philo : no arguments");
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