/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:58:02 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/30 14:25:21 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void	ft_sleep(t_data *philo, int time)
{
	int			i;
	long int	time_now;

	time_now = get_time(philo);
	i = 0;
	while (i < 10 * time)
	{
		i++;
		if (get_time(philo) - time_now >= time)
			break ;
		usleep(100);
	}
}

long	get_time(t_data *philo)
{
	struct timeval	tp;
	long			ms;

	gettimeofday(&tp, NULL);
	ms = tp.tv_sec * 1000;
	ms += tp.tv_usec / 1000;
	return (ms - philo->time_start);
}

int	complete_values2(t_data *philo)
{
	int	i;

	i = -1;
	philo->has_eat = (int *)malloc(sizeof(int) * philo->nbr_of_philo);
	if (!philo->has_eat)
		return (1);
	while (++i < philo->nbr_of_philo)
		philo->has_eat[i] = 0;
	i = -1;
	philo->last_eat = (long int *)malloc(sizeof(long int)
			* philo->nbr_of_philo);
	if (!philo->last_eat)
		return (1);
	while (++i < philo->nbr_of_philo)
		philo->last_eat[i] = 0;
	return (0);
}

int	complete_values(t_data *philo)
{
	int	i;

	philo->iter = (int *)malloc(sizeof(int) * philo->nbr_of_philo);
	if (!philo->iter)
		return (1);
	i = -1;
	while (++i < philo->nbr_of_philo)
		philo->iter[i] = i;
	i = -1;
	philo->count_eat = (int *)malloc(sizeof(int) * philo->nbr_of_philo);
	if (!philo->count_eat)
		return (1);
	while (++i < philo->nbr_of_philo)
		philo->count_eat[i] = 0;
	return (complete_values2(philo));
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
