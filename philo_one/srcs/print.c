/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:57:55 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/30 14:38:22 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_one.h"

void	print_str(t_data *philo, int phi, char *mess)
{
	char	*time;
	char	*philo_str;
	char	*str;

	pthread_mutex_lock(&philo->global_mutex);
	time = ft_itoa((int)get_time(philo));
	philo_str = ft_itoa(phi);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo_str);
	str = ft_strjoin_free_all(str, mess);
	printf("%s", str);
	free(str);
	pthread_mutex_unlock(&philo->global_mutex);
}

void	print_str_eat(t_data *philo, int i)
{
	char	*philo_str;
	char	*time;
	char	*str;
	char	*mess;

	pthread_mutex_lock(&philo->global_mutex);
	time = ft_itoa((int)(get_time(philo)));
	mess = ft_strdup(" is eating\n");
	philo_str = ft_itoa(i);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo_str);
	str = ft_strjoin_free_all(str, mess);
	printf("%s", str);
	philo->count_eat[i - 1]++;
	free(str);
	pthread_mutex_unlock(&philo->global_mutex);
}

void	print_str_dead(t_data *philo, int i, long int diff)
{
	char	*philo_str;
	char	*time;
	char	*str;
	char	*mess;

	mess = ft_strdup(" died\n");
	philo_str = ft_itoa(i);
	time = ft_itoa((int)diff);
	str = ft_strjoin_free(time, " ");
	str = ft_strjoin_free_all(str, philo_str);
	str = ft_strjoin_free_all(str, mess);
	pthread_mutex_lock(&philo->global_mutex);
	printf("%s", str);
	free(str);
	pthread_mutex_unlock(&philo->dead_mutex);
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

t_data	*get_struct(void)
{
	static t_data	philo;

	return (&philo);
}
