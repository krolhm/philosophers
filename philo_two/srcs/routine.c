/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:30:25 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/30 14:27:26 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_two.h"

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

int	eating(t_data *philo, int i)
{
	if (philo->status == -1)
	{
		print_str_eat(philo, i + 1);
		philo->last_eat[i] = get_time(philo);
		ft_sleep(philo, philo->time_to_eat);
	}
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
			sem_wait(philo->sem_global);
			philo->status = 1;
			sem_post(philo->sem_dead);
		}
		usleep(4000);
	}
	return (arg);
}

void	*routine(void *arg)
{
	t_data		*philo;
	int			i;

	philo = get_struct();
	i = *(int *)arg;
	philo->last_eat[i] = get_time(philo);
	while (philo->status == -1)
	{
		thinking(philo, i);
		sem_wait(philo->sem_forks);
		sem_wait(philo->sem_forks);
		print_str(philo, i + 1, ft_strdup(" has taken a fork\n"));
		eating(philo, i);
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		sleeping(philo, i);
	}
	return (0);
}
