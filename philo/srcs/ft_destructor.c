/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destructor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:13:36 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/20 15:16:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destructor(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->philo_num)
		pthread_mutex_destroy(&philo->data->arr_fork[i]);
}
