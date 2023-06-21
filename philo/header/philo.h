/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:06:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/21 17:14:58 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_data
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eating_times;
	bool			optional_arg;
	pthread_mutex_t	*arr_fork;
}	t_data;

typedef struct s_mutex
{
	pthread_mutex_t	*death;
	pthread_mutex_t	*timing;
	pthread_mutex_t	*printing;
	pthread_mutex_t	*eating;
}	t_mutex;

typedef struct s_philo
{
	int					left_fork;
	int					right_fork;
	int					id;
	long long unsigned	last_meal;
	long long unsigned	time_delay;
	bool                *death_check;
	bool                *eat_check;
	pthread_t			thread;
	t_data				*data;
	t_mutex				*mutex;
}	t_philo;

/*  ERRORS  */
int		ft_strerror(char *str_error, int return_value);
int		ft_check_errors(int ac, char **av);
/*  INIT    */
void	ft_init_monitoring(t_philo *philo);
void	ft_init_threads(t_philo *philo);
t_philo	*ft_init_forks(t_data *data, t_mutex *mutex);
t_mutex	*ft_init_mutex(t_mutex *mutex);
t_data	*ft_init_data(char **av, bool optional);
/*	ROUTINE	*/
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
void	*ft_routine(void *arg);
/*  UTILS   */
void	ft_print_info(t_philo *philo, char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(char *str);
bool	ft_isdigit(int c);
/*  MONITORING_UTILS   */
bool	ft_eat_amount_check(t_philo *philo, int i);
/*  TIME HANDLER  */
long long unsigned	ft_timer(long long unsigned diff, pthread_mutex_t *timing);
long long unsigned	ft_get_time(void);
/*  THREAD  */
void	*ft_monitoring(void *arg);
/*  DESTRUCTOR  */
void	ft_destructor(t_philo *philo);

#endif
