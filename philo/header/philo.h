/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:06:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/20 15:18:57 by cscelfo          ###   ########.fr       */
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
	int				eating_times; //optional argument
	bool			optional_arg;
	bool			flag_watcher;
	pthread_mutex_t	*arr_fork;
}	t_data;

typedef struct s_mutex
{
	pthread_mutex_t	*death;
	pthread_mutex_t	*timer;
	pthread_mutex_t	*print;
	pthread_mutex_t	*eat_check;
}	t_mutex;

typedef struct s_philo
{
	pthread_t			thread;
	int					left_fork;
	int					right_fork;
	int					id;
	long long unsigned	last_meal;
	long long unsigned	time_delay;
	t_data				*data;
	t_mutex				*mutex;
}	t_philo;

/*  ERRORS  */
int		ft_strerror(char *str_error, int return_value);
int		ft_check_errors(int ac, char **av);
/*  INIT    */
t_data	*ft_init_data(char **av, bool optional);
t_mutex	*ft_init_mutex(t_mutex *mutex);
t_philo	*ft_init_forks(t_data *data, t_mutex *mutex);
void	ft_init_threads(t_philo *philo);
/*  UTILS   */
void	ft_print_info(t_philo *philo, char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(char *str);
bool	ft_isdigit(int c);
/*  ROUTINE_UTILS   */
bool	ft_eat_amount_check(t_philo *philo, int i);
/*  TIME HANDLER  */
long long unsigned	ft_timer(long long unsigned diff, pthread_mutex_t *timer);
long long unsigned	ft_get_time(void);
/*  THREAD  */
void	*ft_routine(void *arg);
void	*ft_monitoring(void *arg);
/*  DESTRUCTOR  */
void	ft_destructor(t_philo *philo);

#endif
