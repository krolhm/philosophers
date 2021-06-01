/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:31:03 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/30 14:27:39 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

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
