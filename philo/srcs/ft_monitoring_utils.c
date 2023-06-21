/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:18:14 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/21 17:18:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_eat_amount_check(t_philo *philo, int i)
{
	static int	satollo;

	pthread_mutex_lock(philo->mutex->eating);
	if (philo[i].data->eating_times == 0)
		satollo++;
	if (satollo == philo->data->philo_num)
		return (true);
	pthread_mutex_unlock(philo->mutex->eating);
	return (false);
}
