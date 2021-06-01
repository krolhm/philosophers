/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:30:29 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/01 12:02:04 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

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
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds - philo->t_start);
}
