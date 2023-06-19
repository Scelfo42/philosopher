/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:39:15 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/19 15:25:07 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_timer(int start_time, pthread_mutex_t *timer)
{
    struct timeval  time;
    int             updated_time;

    pthread_mutex_lock(timer);
    gettimeofday(&time, NULL);
    updated_time = ((int)time.tv_sec * 1000) + ((int)time.tv_usec / 1000) - start_time;
    pthread_mutex_unlock(timer);
	return (updated_time);
}

int    ft_get_time(void)
{
    struct timeval time;
    int  time_s;
    int  time_us;

    gettimeofday(&time, NULL);
    time_s = (int)time.tv_sec * 1000;
    time_us = (int)time.tv_usec / 1000;
    return (time_s + time_us);
}
