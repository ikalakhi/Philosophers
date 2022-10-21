/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:38:33 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/10/07 09:38:40 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int main(int ac, char **av)
{
    t_philo     *philo;
    t_comp      *comp;
    int         num_philo;

    if (ac == 5 || ac == 6)
    {
        check_numbers(av);
        num_philo = ft_atoi(av[1]);
        if (num_philo == 0)
            error("ERROR: number of philo is not valide!\n");
        comp = malloc(sizeof(t_comp) * 1);
        philo = malloc(sizeof(t_philo) * num_philo);
        if (!comp || !philo)
            return(0);
        atoi_initialize(av, philo);
        forkes_initialize(philo, num_philo);
        create_threads(philo, num_philo);
    }
    else
        error("ERROR: number of arguments is not valide!\n");
    return (0);
}
