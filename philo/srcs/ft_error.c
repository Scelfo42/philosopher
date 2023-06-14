/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:39:34 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/14 18:08:09 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_threads_error(void)
{
    printf("It is suggested, so i force you, to use less threads. TY");
    return (4);
}

int ft_negative_error(void)
{
    printf("YO CHILL! You cannot pass a negative number");
    return (3);
}

int ft_digit_error(void)
{
    printf("You MUST pass a digit, bruv\n");
    return (2);
}

int ft_arg_error(void)
{
    printf("Number of arguments. Watch the subject, you twat\n");
    return (1);
}

bool    ft_check_error(int ac, char **av)
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
                return (ft_digit_error());
        }
        if (ft_atoi(av[i]) < 0)
            return (ft_negative_error());
        if (i == 1)
        {
            if (ft_atoi(av[i]) > 100)
                return (ft_threads_error());
        }
    }
}
