/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:50:09 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/17 14:56:03 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_sleep(t_philo *philo)
{
    printf("%d is sleeping\n", philo->id);
    usleep(philo->data->time_to_sleep);
}

void    ft_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->arr_fork[philo->left_fork]);
    printf("%d has taken the left fork\n", philo->id);
    pthread_mutex_lock(&philo->data->arr_fork[philo->right_fork]);
    printf("%d has taken the right fork\n", philo->id);
    printf("%d is eating\n", philo->id);
    usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(&philo->data->arr_fork[philo->left_fork]);
    pthread_mutex_unlock(&philo->data->arr_fork[philo->right_fork]);
}

void    *ft_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (philo->data->flag_watcher == false)
    {
        ft_eat(philo);
        ft_sleep(philo);
    }
    return (NULL);
}
