/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:15:21 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/15 18:00:56 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    bool    optional;
    t_data  *data;
    t_philo *philo;

    optional = false;
    data = NULL;
    philo = NULL;
    if (ac == 6)
        optional = true; // if optional argument is used
    else if (ac < 5 || ac > 6)
        return (ft_strerror("Number of arguments is wrong. Watch the subject, you twat", 1));
    if (!ft_check_errors(ac, av))
    {
        data = ft_init_data(av, optional);
        philo = ft_init_forks(data);
        //create threads, philosophers and loop.
    }
    else
        return (ft_strerror("Arguments given apparently have some errors, good luck finding that out.", 5));
    return (0);
}
