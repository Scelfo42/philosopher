/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:33:27 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/20 17:55:57 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_threads(t_philo *philo)
{
	pthread_t	monitoring;
	int			i;

	i = 0;
	while (i < philo->data->philo_num)
	{
		philo[i].time_delay = ft_get_time();
		philo[i].last_meal = philo[i].time_delay;
		printf("Creating thread %d\n", i);
		pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]);
		i++;
	}
	i = 0;
	pthread_create(&monitoring, NULL, ft_monitoring, philo);
	pthread_join(monitoring, NULL);
	while (i < philo->data->philo_num)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

t_philo	*ft_init_forks(t_data *data, t_mutex *mutex)
{
	t_philo	*philo;
	int		i;

	philo = calloc(data->philo_num, sizeof(t_philo));
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->arr_fork[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		philo[i].right_fork = i;
		if (i == data->philo_num - 1)
			philo[i].left_fork = 0;
		else
			philo[i].left_fork = i + 1;
		philo[i].id = i;
		philo[i].data = data;
		philo[i].mutex = mutex;
		i++;
	}
	return (philo);
}

t_mutex	*ft_init_mutex(t_mutex *mutex)
{
	mutex = ft_calloc(1, sizeof(t_mutex));
	mutex->death = ft_calloc(1, sizeof(pthread_mutex_t));
	mutex->print = ft_calloc(1, sizeof(pthread_mutex_t));
	mutex->timer = ft_calloc(1, sizeof(pthread_mutex_t));
	mutex->eat_check = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex->death, NULL);
	pthread_mutex_init(mutex->print, NULL);
	pthread_mutex_init(mutex->timer, NULL);
	pthread_mutex_init(mutex->eat_check, NULL);
	return (mutex);
}

t_data	*ft_init_data(char **av, bool optional)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]) * 1000;
	data->time_to_eat = ft_atoi(av[3]) * 1000;
	data->time_to_sleep = ft_atoi(av[4]) * 1000;
	data->optional_arg = false;
	if (optional == true)
	{
		data->eating_times = ft_atoi(av[5]);
		data->optional_arg = true;
	}
	data->arr_fork = ft_calloc(data->philo_num, sizeof(pthread_mutex_t));
	return (data);
}
