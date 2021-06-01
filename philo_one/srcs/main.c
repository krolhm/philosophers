/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:55:27 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/30 14:23:27 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

int	eat_counter(void)
{
	int		i;
	t_data	*philo;

	philo = get_struct();
	i = 0;
	while (i < philo->nbr_of_philo)
	{
		if (philo->count_eat[i] == philo->nbr_of_time_each_philo_must_eat)
			philo->has_eat[i] = 1;
		i++;
	}
	i = 0;
	while (i < philo->nbr_of_philo)
	{
		if (philo->has_eat[i] == 0)
			return (-1);
		i++;
	}
	if (philo->nbr_of_time_each_philo_must_eat > 0)
		return (1);
	return (0);
}

int	destroy_mutex(t_data *philo)
{
	int		i;

	i = 0;
	while (i < philo->nbr_of_philo)
	{
		pthread_mutex_destroy(&philo->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->global_mutex);
	pthread_mutex_destroy(&philo->dead_mutex);
	return (0);
}

int	init(t_data *philo)
{
	int	i;

	philo->mutex = malloc(sizeof(pthread_mutex_t) * philo->nbr_of_philo);
	memset(philo->mutex, 0, philo->nbr_of_philo * 8);
	philo->thread = malloc(sizeof(pthread_t) * philo->nbr_of_philo);
	memset(philo->thread, 0, philo->nbr_of_philo * 8);
	pthread_mutex_init(&philo->global_mutex, NULL);
	pthread_mutex_init(&philo->dead_mutex, NULL);
	pthread_mutex_lock(&philo->dead_mutex);
	i = -1;
	while (++i < philo->nbr_of_philo)
		pthread_mutex_init(&philo->mutex[i], NULL);
	return (0);
}

int	philo_in_action(t_data *philo)
{
	int	i;

	init(philo);
	i = -1;
	while (++i < philo->nbr_of_philo)
		pthread_create(&philo->thread[i], NULL, &routine, &philo->iter[i]);
	pthread_create(&philo->thread_time, NULL, &routine_time, NULL);
	pthread_mutex_lock(&philo->dead_mutex);
	destroy_mutex(philo);
	return (0);
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
