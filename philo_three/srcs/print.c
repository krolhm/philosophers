/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:31:06 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/31 11:29:12 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_three.h"

void	print_str(t_data *philo, int phi, char *mess)
{
	char	*time;
	char	*philo_str;
	char	*str;

	sem_wait(philo->sem_global);
	time = ft_itoa((int)get_time(philo));
	philo_str = ft_itoa(phi);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo_str);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	free(str);
	sem_post(philo->sem_global);
}

void	print_str_eat(t_data *philo, int i)
{
	char	*philo_str;
	char	*time;
	char	*str;
	char	*mess;

	sem_wait(philo->sem_global);
	time = ft_itoa((int)(get_time(philo)));
	mess = ft_strdup(" is eating\n");
	philo_str = ft_itoa(i);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo_str);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	philo->count_eat++;
	free(str);
	sem_post(philo->sem_global);
}

void	print_str_dead(t_data *philo, int i, long int diff)
{
	char	*philo_str;
	char	*time;
	char	*str;
	char	*mess;

	sem_wait(philo->sem_global);
	mess = ft_strdup(" died\n");
	philo_str = ft_itoa(i);
	time = ft_itoa((int)diff);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo_str);
	str = ft_strjoin_free_all(str, mess);
	write(1, str, ft_strlen(str));
	free(str);
	i = 0;
	while (i < philo->nbr_of_philo)
	{
		sem_post(philo->sem_eat);
		i++;
	}
}
