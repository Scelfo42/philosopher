/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:39:34 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/24 15:44:16 by cscelfo          ###   ########.fr       */
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
	if (ft_atoi(av[1]) == 0)
		return (ft_strerror("No philo, no fun.", 2));
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]))
				return (ft_strerror("You MUST pass a number", 3));
			else if (ft_atoi(av[i]) < 0)
				return (ft_strerror("You cannot pass a negative number", 4));
			if (i == 1 && ft_atoi(av[1]) > 100)
				return (ft_strerror("I don't want to explode", 5));
			if (i == 5 && ft_atoi(av[5]) == 0)
				return (ft_strerror("Let these philosopher eat", 6));
		}
	}
	return (0);
}
