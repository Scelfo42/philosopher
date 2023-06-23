/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:29:45 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/23 17:53:33 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_rip(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex->death);
	if (*(philo->death_check) == false)
	{
		pthread_mutex_unlock(philo->mutex->death);
		return (false);
	}
	pthread_mutex_unlock(philo->mutex->death);
	return (true);
}

int	ft_forever_alone(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->arr_fork[philo->right_fork]);
	ft_print_info(philo, "has taken the right fork");
	pthread_mutex_unlock(&philo->data->arr_fork[philo->right_fork]);
	return (1);
}

void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->data->arr_fork[philo->left_fork];
	right_fork = &philo->data->arr_fork[philo->right_fork];
	if (left_fork < right_fork)
	{
		pthread_mutex_lock(left_fork);
		ft_print_info(philo, "has taken the left fork");
		pthread_mutex_lock(right_fork);
		ft_print_info(philo, "has taken the right fork");
	}
	else
	{
		pthread_mutex_lock(right_fork);
		ft_print_info(philo, "has taken the right fork");
		pthread_mutex_lock(left_fork);
		ft_print_info(philo, "has taken the left fork");
	}
}

int	ft_bonus_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex->eating);
	if (--philo->eating_times == 0)
	{
		ft_print_info(philo, "is satollo!");
		pthread_mutex_unlock(philo->mutex->eating);
		return (2);
	}
	pthread_mutex_unlock(philo->mutex->eating);
	return (0);
}
