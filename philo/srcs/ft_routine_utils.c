/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:29:45 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/22 18:32:10 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->data->arr_fork[philo->left_fork];
	right_fork = &philo->data->arr_fork[philo->right_fork];
	if (left_fork < right_fork)
	{
		pthread_mutex_lock(left_fork);
		pthread_mutex_lock(right_fork);
		ft_print_info(philo, "has taken the left fork");
		ft_print_info(philo, "has taken the right fork");
	}
	else
	{
		pthread_mutex_lock(right_fork);
		pthread_mutex_lock(left_fork);
		ft_print_info(philo, "has taken the right fork");
		ft_print_info(philo, "has taken the left fork");
	}
}

int	ft_forever_alone(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->arr_fork[philo->right_fork]);
	ft_print_info(philo, "has taken the right fork");
	return (1);
}

int	ft_bonus_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex->eating);
	philo->eating_times--;
	if (philo->eating_times == 0)
	{
		ft_print_info(philo, "is satollo!");
		pthread_mutex_unlock(philo->mutex->eating);
		return (2);
	}
	pthread_mutex_unlock(philo->mutex->eating);
	return (0);
}
