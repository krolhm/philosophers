/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:44:27 by rbourgea          #+#    #+#             */
/*   Updated: 2021/05/30 14:25:43 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_data
{
	int			nbr_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_of_time_each_philo_must_eat;
	long int	time_start;
	int			*count_eat;
	int			*has_eat;
	int			*iter;
	pthread_t	*thread;
	pthread_t	thread_time;
	sem_t		*sem_forks;
	sem_t		*sem_global;
	sem_t		*sem_dead;
	long int	*last_eat;
	int			status;
}				t_data;

void			*routine(void *arg);
void			*routine_time(void *arg);
t_data			*get_struct(void);
int				eating(t_data *philo, int i);
int				sleeping(t_data *philo, int i);
int				thinking(t_data *philo, int i);

int				eat_counter(void);
int				is_digit(char *str);
int				parse_values(t_data *philo, int argc, char **argv);
int				complete_values(t_data *philo);
long			get_time(t_data *philo);
void			ft_sleep(t_data *philo, int time);
int				check_time(t_data *philo);

void			print_str_dead(t_data *philo, int i, long int diff);
void			print_str_eat(t_data *philo, int i);
void			print_str(t_data *philo, int phi, char *mess);

int				error_arg(int argc, char **argv);
int				init_struct(t_data *philo);
int				free_all(t_data *philo);

long long		ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strjoin_free_all(char *s1, char *s2);

#endif
