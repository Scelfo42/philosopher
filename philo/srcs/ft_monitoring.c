/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:26:19 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/22 18:33:09 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitoring(void *arg)
{
	t_philo					*philo;
	int						i;
	long long unsigned		die_time;
	long long unsigned		diff;

	philo = (t_philo *)arg;
	i = 0;
	die_time = philo->data->time_to_die / 1000;
	while (1)
	{
		if (i == philo->data->philo_num)
			i = 0;
		pthread_mutex_lock(philo[i].mutex->last_meal);
		diff = ft_timer(philo[i].last_meal, philo[i].mutex->timing);
		pthread_mutex_unlock(philo[i].mutex->last_meal);
		if (diff > die_time)
		{
			ft_declare_death(&philo[i]);
			break ;
		}
		if (philo->data->optional_arg == true && ft_eat_amount_check(philo))
			break ;
		i++;
	}
	return (NULL);
}
