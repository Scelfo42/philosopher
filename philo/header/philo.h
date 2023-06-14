/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:06:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/14 18:44:43 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

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
}   t_data;

typedef struct s_philo
{
    pthread_t       *philo;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_data          *data;
}   t_philo;

/*  ERRORS  */
int    ft_check_errors(int ac, char **av);
int     ft_arg_error(void);
int     ft_digit_error(void);
int     ft_negative_error(void);
int     ft_threads_error(void);
/*  UTILS   */
void    *ft_calloc(size_t nmemb, size_t size);
bool    ft_isdigit(int c);
int     ft_atoi(char *str);
/*  INIT    */
t_data  *ft_init_data(char **av, bool optional);
/*  START   */
void    ft_daje_roma(t_data *data, bool optional);

#endif
