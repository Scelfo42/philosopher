/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:50:09 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/23 17:43:17 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	ft_print_info(philo, "is sleeping...");
	usleep(philo->data->time_to_sleep);
	ft_print_info(philo, "is thinking...");
	//usleep(500);
}

int	ft_eat(t_philo *philo)
{
	if (philo->left_fork == philo->right_fork)
		return (ft_forever_alone(philo));
	if (philo->id == philo->data->philo_num)
		usleep(1000);
	ft_take_forks(philo);
	ft_print_info(philo, "is eating...");
	pthread_mutex_lock(philo->mutex->last_meal);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->mutex->last_meal);
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->arr_fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->arr_fork[philo->right_fork]);
	if (philo->data->optional_arg == true)
		return (ft_bonus_eat(philo));
	return (0);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
			usleep(500);
	while (!ft_rip(philo))
	{
		if (ft_eat(philo))
			break ;
		usleep(500);
		ft_sleep(philo);
	}
	return (NULL);
}
