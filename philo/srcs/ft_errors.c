/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:39:34 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/15 16:29:16 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strerror(char *str, int return_value)
{
    printf("%s\n", str);
    return (return_value);
}

int    ft_check_errors(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    while (++i < ac)
    {
        j = -1;
        while (av[i][++j])
        {
            if (!ft_isdigit(av[i][j]))
                return (ft_strerror("You MUST pass a digit, bruv", 2));
        }
        if (ft_atoi(av[i]) < 0)
            return (ft_strerror("YO CHILL! You cannot pass a negative number", 3));
        if (i == 1)
        {
            if (ft_atoi(av[i]) > 100)
                return (ft_strerror("It is suggested, so i force you, to use less threads. TY", 4));
        }
    }
    return (0);
}
