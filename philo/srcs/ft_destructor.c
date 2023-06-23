/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destructor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:13:36 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/23 15:33:05 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destructor(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->philo_num)
		pthread_mutex_destroy(&philo->data->arr_fork[i]);
	pthread_mutex_destroy(philo->mutex->death);
	pthread_mutex_destroy(philo->mutex->printing);
	pthread_mutex_destroy(philo->mutex->timing);
	pthread_mutex_destroy(philo->mutex->eating);
	pthread_mutex_destroy(philo->mutex->last_meal);
	free(philo->data->arr_fork);
	free(philo->mutex->death);
	free(philo->mutex->printing);
	free(philo->mutex->timing);
	free(philo->mutex->eating);
	free(philo->mutex->last_meal);
	free(philo->mutex);
	free(philo->data);
	free(philo);
}
