/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:57:15 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/30 14:43:47 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

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

int	free_all(t_data *philo)
{
	free(philo->count_eat);
	free(philo->has_eat);
	free(philo->iter);
	free(philo->last_eat);
	free(philo->mutex);
	free(philo->thread);
	return (0);
}

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}
