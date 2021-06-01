/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:58:08 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/01 11:04:32 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

int	init(t_data *philo)
{
	sem_unlink("sem_eat");
	philo->sem_eat = sem_open("sem_eat", O_CREAT, 0660, philo->nbr_of_philo);
	if (philo->sem_eat == SEM_FAILED)
		return (1);
	sem_unlink("sem_forks");
	philo->sem_forks = sem_open("sem_forks",
			O_CREAT, 0660, philo->nbr_of_philo);
	if (philo->sem_forks == SEM_FAILED)
		return (1);
	sem_unlink("sem_global");
	philo->sem_global = sem_open("sem_global", O_CREAT, 0660, 1);
	if (philo->sem_global == SEM_FAILED)
		return (1);
	return (0);
}

int	philo_in_action(t_data *philo, int i)
{
	if (init(philo))
		return (1);
	while (++i < philo->nbr_of_philo)
		sem_wait(philo->sem_eat);
	i = 0;
	while (i < philo->nbr_of_philo)
	{
		philo->pid[i] = fork();
		philo->philo = i + 1;
		if (philo->pid[i] == 0)
		{
			pthread_create(&philo->thread_time, NULL, &routine_time, NULL);
			routine(philo);
		}
		i++;
	}
	i = -1;
	while (++i < philo->nbr_of_philo)
		sem_wait(philo->sem_eat);
	i = -1;
	while (++i < philo->nbr_of_philo)
		kill(philo->pid[i], SIGKILL);
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
	philo->t_start = get_time(philo);
	if (philo_in_action(philo, -1))
		return (0);
	free_all(philo);
	return (0);
}
