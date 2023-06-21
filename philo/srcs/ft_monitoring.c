/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:26:19 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/21 17:47:49 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitoring(void *arg)
{
	t_philo					*philo;
	int						i;
	long long unsigned		die_time;

	philo = (t_philo *)arg;
	i = 0;
	die_time = philo->data->time_to_die / 1000;
	while (1)
	{
		if (i == philo->data->philo_num)
			i = 0;
		if (ft_timer(philo[i].last_meal, philo[i].mutex->timing) > die_time)
		{
			ft_print_info(&philo[i], "has died!");
			pthread_mutex_lock(philo[i].mutex->death);
			*philo[i].death_check = true;
			pthread_mutex_unlock(philo[i].mutex->death);
			break ;
		}
		if (philo->data->optional_arg && ft_eat_amount_check(philo, i))
		{
			ft_print_info(&philo[i], "is satollo!");
			pthread_mutex_lock(philo[i].mutex->eating);
			*philo[i].eat_check = true;
			pthread_mutex_unlock(philo[i].mutex->eating);
			break ;
		}
		i++;
	}
	return (NULL);
}
