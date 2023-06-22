/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:00:42 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/22 18:34:52 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_info(t_philo *philo, char *str)
{
	long long unsigned	timer;

	timer = ft_timer(philo->time_delay, philo->mutex->timing);
	pthread_mutex_lock(philo->mutex->printing);
	if (!ft_rip(philo))
		printf("[%llu] %d %s\n", timer, philo->id, str);
	pthread_mutex_unlock(philo->mutex->printing);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new_memory;
	size_t	bob;

	bob = nmemb * size;
	if (bob < nmemb)
		return (NULL);
	new_memory = malloc(bob);
	if (!new_memory)
		return (NULL);
	memset(new_memory, 0, bob);
	return (new_memory);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i]) && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

bool	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || (c == '+' || c == '-'))
		return (true);
	return (false);
}
