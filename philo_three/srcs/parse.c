/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:30:10 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/31 11:30:11 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

int	complete_values(t_data *philo)
{
	int	i;

	i = -1;
	philo->has_eat = (int *)malloc(sizeof(int) * philo->nbr_of_philo);
	if (!philo->has_eat)
		return (1);
	while (++i < philo->nbr_of_philo)
		philo->has_eat[i] = 0;
	i = -1;
	philo->pid = (int *)malloc(sizeof(long int) * philo->nbr_of_philo);
	if (!philo->pid)
		return (1);
	while (++i < philo->nbr_of_philo)
		philo->pid[i] = 0;
	return (0);
}

int	parse_values(t_data *philo, int argc, char **argv)
{
	philo->nbr_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (philo->nbr_of_philo < 2)
		return (1);
	if (philo->time_to_die < 0)
		return (1);
	if (philo->time_to_eat < 0)
		return (1);
	if (philo->time_to_sleep < 0)
		return (1);
	if (argc == 6)
		philo->nbr_of_time_each_philo_must_eat = ft_atoi(argv[5]);
	else
		philo->nbr_of_time_each_philo_must_eat = 0;
	return (0);
}
