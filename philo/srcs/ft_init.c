/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:33:27 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/17 14:53:44 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_init_threads(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->data->philo_num)
    {
        if (i % 2 != 0)
            usleep(1000);
        printf("Thread %d started successfully", i);
        pthread_create(&philo[i].thread, NULL, ft_routine, (void *)&philo[i]);
        i++;
    }
    i = 0;
    while (i < philo->data->philo_num)
    {
        pthread_join(philo[i].thread, NULL);
        i++;
    }
}

t_philo *ft_init_forks(t_data *data)
{
    t_philo *philo;
    int     i;

    philo = ft_calloc(data->philo_num, sizeof(t_philo));
    i = 0;
    while (i < data->philo_num)
        pthread_mutex_init(&data->arr_fork[i++], NULL);
    i = 0;
    while (i < data->philo_num)
    {
        philo[i].right_fork = i;
        if (i == data->philo_num - 1)
            philo[i].left_fork = 0;
        else
            philo[i].left_fork = i + 1;
        philo[i].id = i;
        i++;
    }
    return (philo);
}

t_data    *ft_init_data(char **av, bool optional)
{
    t_data  *data;

    data = ft_calloc(1, sizeof(t_data *));
    data->philo_num = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]) * 1000;  // * 1000 serve per la conversione da secondi a millisecondi!
    data->time_to_eat = ft_atoi(av[3]) * 1000;
    data->time_to_sleep = ft_atoi(av[4]) * 1000;
    data->optional_arg = false;
    if (optional == true)
    {
        data->eating_times = ft_atoi(av[5]);
        data->optional_arg = true;
    }
    data->arr_fork = ft_calloc(data->philo_num, sizeof(pthread_mutex_t));
    return (data);
}
