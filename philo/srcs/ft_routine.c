/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:50:09 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/21 18:47:10 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *philo)
{
	ft_print_info(philo, "is sleeping...");
	usleep(philo->data->time_to_sleep);
	ft_print_info(philo, "is thinking...");
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->arr_fork[philo->left_fork]);
	ft_print_info(philo, "has taken the left fork");
	pthread_mutex_lock(&philo->data->arr_fork[philo->right_fork]);
	ft_print_info(philo, "has taken the right fork");
	ft_print_info(philo, "is eating...");
	philo->last_meal = ft_get_time();
	if (philo->data->eating_times == true)
		philo->data->eating_times--;
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->arr_fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->arr_fork[philo->right_fork]);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (*(philo->death_check) == false && *(philo->eat_check) == false)
	{
		if (philo->id % 2 == 0)
			usleep(1000);
		ft_eat(philo);
		ft_sleep(philo);
	}
	return (NULL);
}