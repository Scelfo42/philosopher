/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:18:14 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/22 18:33:51 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_declare_death(t_philo *philo)
{
	ft_print_info(philo, "has died!");
	pthread_mutex_lock(philo->mutex->death);
	*philo->death_check = true;
	pthread_mutex_unlock(philo->mutex->death);
}

bool	ft_eat_amount_check(t_philo *philo)
{
	int	satolli;
	int	i;

	i = 0;
	satolli = 0;
	pthread_mutex_lock(philo->mutex->eating);
	while (i < philo->data->philo_num)
	{
		if (philo[i].eating_times == 0)
			satolli++;
		i++;
	}
	if (satolli == philo->data->philo_num)
		return (true);
	pthread_mutex_unlock(philo->mutex->eating);
	return (false);
}
