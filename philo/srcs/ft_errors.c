/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:39:34 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/20 14:30:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strerror(char *str, int return_value)
{
	printf("%s\n", str);
	return (return_value);
}

int	ft_check_errors(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]))
				return (ft_strerror("You MUST pass a number", 2));
			else if (ft_atoi(av[i]) < 0)
				return (ft_strerror("You cannot pass a negative number", 3));
			if (i == 1 && ft_atoi(av[1]) > 100)
				return (ft_strerror("I don't want to explode", 4));
		}
	}
	return (0);
}
