/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:38:18 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/30 14:23:40 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_time_each_philo_must_eat;
	pthread_t		*thread;
	pthread_t		thread_time;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	global_mutex;
	pthread_mutex_t	dead_mutex;
	int				*count_eat;
	int				*has_eat;
	int				*iter;
	long int		*last_eat;
	long int		time_start;
	int				status;
}					t_data;

void				*routine(void *arg);
void				*routine_time(void *arg);
int					eat_counter(void);
t_data				*get_struct(void);

int					print_array(t_data *philo);
int					init_struct(t_data *philo);
int					parse_values(t_data *philo, int argc, char **argv);
int					complete_values(t_data *philo);
long				get_time(t_data *philo);
void				print_str_dead(t_data *philo, int i, long int diff);
void				print_str_eat(t_data *philo, int i);
void				print_str(t_data *philo, int phi, char *mess);
void				ft_sleep(t_data *philo, int time);

int					is_digit(char *str);
int					error_arg(int argc, char **argv);
int					ft_free_str(char **str, int result);
int					free_all(t_data *philo);
int					ft_free_int(int i, int result);
int					check_time(t_data *philo);

char				*ft_itoa(int n);
long long			ft_atoi(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strjoin_free_all(char *s1, char *s2);

#endif
