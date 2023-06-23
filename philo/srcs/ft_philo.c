/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:15:21 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/23 15:39:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	bool		optional;
	t_data		*data;
	t_philo		*philo;
	t_mutex		*mutex;

	optional = false;
	data = NULL;
	philo = NULL;
	mutex = NULL;
	if (ac == 6)
		optional = true;
	else if (ac < 5 || ac > 6)
		return (ft_strerror("Number of arguments is wrong.", 1));
	if (!ft_check_errors(ac, av))
	{
		data = ft_init_data(av, optional);
		if (!data)
			return (6);
		mutex = ft_init_mutex(mutex);
		if (!mutex)
			return (7);
		philo = ft_init_forks(data, mutex, av);
		if (!philo)
			return (8);
		ft_init_threads(philo);
		ft_destructor(philo);
	}
	return (0);
}
