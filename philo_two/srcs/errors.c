/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:44:45 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/30 14:43:33 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

int	error_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5)
	{
		printf("Error: Arguments are missing !\n");
		return (1);
	}
	else if (argc > 6)
	{
		printf("Error: Too many arguments !\n");
		return (1);
	}
	while (i < argc)
	{
		if (!is_digit(argv[i]))
		{
			printf("Error: Bad argument !\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_struct(t_data *philo)
{
	philo->nbr_of_philo = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->nbr_of_time_each_philo_must_eat = 0;
	philo->time_start = 0;
	philo->status = -1;
	return (0);
}

int	free_all(t_data *philo)
{
	free(philo->count_eat);
	free(philo->has_eat);
	free(philo->iter);
	free(philo->last_eat);
	free(philo->thread);
	return (0);
}
