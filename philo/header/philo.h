/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:06:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/19 15:52:37 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

typedef struct s_data
{
    int             philo_num;
    int             time_to_die; //long long unsigned (?)
    int             time_to_eat;
    int             time_to_sleep;
    int             eating_times; //optional argument
    bool            optional_arg;
    bool            flag_watcher;
    pthread_mutex_t *arr_fork;
}   t_data;

typedef struct s_mutex
{
    pthread_mutex_t *death;
    pthread_mutex_t *timer;
    pthread_mutex_t *print;
}   t_mutex;


typedef struct s_philo
{
    pthread_t   thread;
    int         left_fork;
    int         right_fork;
    int         id;
    int         last_meal;
    int         start_time;
    t_data      *data;
    t_mutex     *mutex;
}   t_philo;

/*  ERRORS  */
int     ft_strerror(char *str_error, int return_value);
int     ft_check_errors(int ac, char **av);
/*  UTILS   */
void    *ft_calloc(size_t nmemb, size_t size);
bool    ft_isdigit(int c);
int     ft_atoi(char *str);
/*  INIT    */
t_data  *ft_init_data(char **av, bool optional);
t_philo *ft_init_forks(t_data *data, t_mutex *mutex);
t_mutex *ft_init_mutex(t_mutex *mutex);
void    ft_init_threads(t_philo *philo);
t_philo *ft_init_ogniosa(t_philo *philo, t_data *data, t_mutex *mutex, int index);
/*  TIME HANDLER  */
int     ft_get_time(void);
int     ft_timer(int start_time, pthread_mutex_t *timer);
/*  THREAD  */
void    *ft_routine(void *arg);
void	*ft_monitoring(void *arg);
void    ft_print_info(t_philo *philo, char *str);

#endif
