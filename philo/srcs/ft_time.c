/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:39:15 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/20 17:59:28 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long unsigned	ft_timer(long long unsigned diff, pthread_mutex_t *timer)
{
	long long unsigned	actual_time;
	
	pthread_mutex_lock(timer);
	actual_time = ft_get_time();
	// printf("\nactual_time: %llu\n", actual_time);
	// printf("\ndiff: %llu\n", diff);
	pthread_mutex_unlock(timer);
	return (actual_time - diff);
}

long long unsigned	ft_get_time(void)
{
	struct timeval		time;
	long long unsigned	actual_time;

	gettimeofday(&time, NULL);
	actual_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (actual_time);
}
