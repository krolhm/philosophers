/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:27:19 by rbourgea          #+#    #+#             */
/*   Updated: 2021/06/01 11:03:53 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

int	eating(t_data *philo)
{
	if (philo->status == -1)
	{
		philo->last_eat = get_time(philo);
		print_str_eat(philo, philo->philo);
		if (philo->nbr_of_time_each_philo_must_eat > 0
			&& (philo->count_eat >= philo->nbr_of_time_each_philo_must_eat))
		{
			sem_post(philo->sem_eat);
			philo->status = 1;
		}
		ft_sleep(philo, philo->time_to_eat);
	}
	return (1);
}

int	sleeping(t_data *philo)
{
	char		*mess;

	mess = ft_strdup(" is sleeping\n");
	if (philo->status == -1)
	{
		print_str(philo, philo->philo, mess);
		ft_sleep(philo, philo->time_to_sleep);
	}
	return (0);
}

int	thinking(t_data *philo)
{
	char		*mess;

	mess = ft_strdup(" is thinking\n");
	if (philo->status == -1)
		print_str(philo, philo->philo, mess);
	return (0);
}

void	*routine_time(void *arg)
{
	t_data	*philo;

	philo = get_struct();
	while (philo->status == -1)
	{
		if ((get_time(philo) - philo->last_eat) > philo->time_to_die)
		{
			philo->status = 1;
			print_str_dead(philo, philo->philo, (get_time(philo)));
			return (0);
		}
		usleep(4000);
	}
	return (arg);
}

void	routine(t_data *philo)
{
	philo->last_eat = get_time(philo);
	while (philo->status == -1)
	{
		thinking(philo);
		sem_wait(philo->sem_forks);
		sem_wait(philo->sem_forks);
		print_str(philo, philo->philo, ft_strdup(" has taken a fork\n"));
		eating(philo);
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		if (philo->status == 1)
			exit(0);
		sleeping(philo);
	}
}
