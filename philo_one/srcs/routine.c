/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:57:23 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/29 11:49:22 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

int	thinking(t_data *philo, int i)
{
	char		*mess;

	mess = ft_strdup(" is thinking\n");
	if (philo->status == -1)
		print_str(philo, i + 1, mess);
	return (0);
}

int	sleeping(t_data *philo, int i)
{
	char		*mess;

	mess = ft_strdup(" is sleeping\n");
	if (philo->status == -1)
	{
		print_str(philo, i + 1, mess);
		ft_sleep(philo, philo->time_to_sleep);
	}
	return (0);
}

int	eating(t_data *philo, int i, int fork, int next_fork)
{
	char		*mess;

	pthread_mutex_lock(&philo->mutex[fork]);
	mess = ft_strdup(" has taken a fork\n");
	print_str(philo, i + 1, mess);
	pthread_mutex_lock(&philo->mutex[next_fork]);
	if (philo->status == -1)
	{
		print_str_eat(philo, i + 1);
		philo->last_eat[i] = get_time(philo);
		ft_sleep(philo, philo->time_to_eat);
	}
	pthread_mutex_unlock(&philo->mutex[fork]);
	pthread_mutex_unlock(&philo->mutex[next_fork]);
	return (0);
}

void	*routine_time(void *arg)
{
	t_data		*philo;
	int			i;

	philo = get_struct();
	while (philo->status == -1)
	{
		i = -1;
		while (++i < philo->nbr_of_philo)
		{
			if ((get_time(philo) - philo->last_eat[i]) > philo->time_to_die)
			{
				philo->status = 1;
				print_str_dead(philo, i + 1, get_time(philo));
				return (0);
			}
		}
		if (eat_counter() > 0)
		{
			pthread_mutex_lock(&philo->global_mutex);
			philo->status = 1;
			pthread_mutex_unlock(&philo->dead_mutex);
		}
		usleep(4000);
	}
	return (arg);
}

void	*routine(void *arg)
{
	t_data		*philo;
	int			fork;
	int			next_fork;
	int			i;

	philo = get_struct();
	i = *(int *)arg;
	fork = i;
	next_fork = (fork + 1) % philo->nbr_of_philo;
	if (i % 2 == 0)
	{
		next_fork = i;
		fork = (next_fork + 1) % philo->nbr_of_philo;
	}
	philo->last_eat[i] = get_time(philo);
	pthread_detach(*philo->thread);
	while (philo->status == -1)
	{
		thinking(philo, i);
		eating(philo, i, fork, next_fork);
		sleeping(philo, i);
	}
	return (0);
}
