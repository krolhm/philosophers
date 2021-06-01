/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:31:35 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/30 14:26:22 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

int	init(t_data *philo)
{
	philo->thread = malloc(sizeof(pthread_t) * philo->nbr_of_philo);
	memset(philo->thread, 0, philo->nbr_of_philo * 8);
	sem_unlink("sem_forks");
	sem_unlink("sem_global");
	sem_unlink("sem_dead");
	philo->sem_dead = sem_open("sem_dead", O_CREAT, 0660, 1);
	if (philo->sem_dead == SEM_FAILED)
		return (1);
	philo->sem_forks = sem_open("sem_forks", O_CREAT, 0660,
			philo->nbr_of_philo);
	if (philo->sem_forks == SEM_FAILED)
		return (1);
	philo->sem_global = sem_open("sem_global", O_CREAT, 0660, 1);
	if (philo->sem_global == SEM_FAILED)
		return (1);
	sem_wait(philo->sem_dead);
	return (0);
}

int	philo_in_action(t_data *philo)
{
	int	i;

	if (init(philo))
		return (0);
	i = -1;
	while (++i < philo->nbr_of_philo)
		pthread_create(&philo->thread[i], NULL, &routine, &philo->iter[i]);
	pthread_create(&philo->thread_time, NULL, &routine_time, NULL);
	sem_wait(philo->sem_dead);
	return (0);
}

t_data	*get_struct(void)
{
	static t_data	philo;

	return (&philo);
}

int	main(int argc, char **argv)
{
	t_data	*philo;

	philo = get_struct();
	if (error_arg(argc, argv))
		return (0);
	if (init_struct(philo))
		return (0);
	if (parse_values(philo, argc, argv))
		return (0);
	if (complete_values(philo))
		return (0);
	philo->time_start = get_time(philo);
	philo_in_action(philo);
	free_all(philo);
	return (0);
}
