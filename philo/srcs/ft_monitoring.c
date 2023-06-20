/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:26:19 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/20 18:08:41 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* WARNING: molto probabilmente e' sbagliato il join nel file init.c, 
questo perche' appena viene lanciato il programma, 
tutti i filosofi vanno completamente a fare in culo
e solo il monitoring parte, fa tutta la sua roba, ovvero un beato cazzo di niente,
poi schianta e partono i filosofi, probabilmente artefici di tutto cio'.
*/

void	*ft_monitoring(void *arg)
{
	t_philo					*philo;
	int						i;
	long long unsigned		die_time;

	philo = (t_philo *)arg;
	i = 0;
	die_time = philo->data->time_to_die / 1000;
	// while (!ft_eat_amount_check(philo, i))
	while (1)
	{
		if (i == philo->data->philo_num)
			i = 0;
		// printf("\n\nlast_meal of philo[%d]: [%llu]\n\n", i, philo[i].last_meal);
		// printf("\n\nactual time: [%llu]\n\n", ft_get_time());
		//printf("\n\ntimer: %llu\n\n", ft_timer(philo[i].last_meal, philo[i].mutex->timer));
		if (ft_timer(philo[i].last_meal, philo[i].mutex->timer) > die_time)
		{
			ft_print_info(philo, "has died!");
			break ;
		}
		i++;
	}
	return (NULL);
}
