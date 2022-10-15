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

void    *hey(void)
{
    void    *i = NULL;

    printf("Philosopher\n");
    return(i);
}

void    create_threads(t_philo *philo)
{
    int         i;
    pthread_t   ph[philo->number_of_philos];

    i = 0;
    while(i < philo->number_of_philos)
    {
        if (pthread_create(&ph[philo->i], NULL, hey, NULL) != 0)
            error("ERROR\n");
        usleep(1);
        i++;
    }
}

int main(int ac, char **av)
{
    t_philo     *philo;

    philo = malloc(sizeof(t_philo) * 1);
    if (ac == 5 || ac == 6)
    {
        check_numbers(av);
        atoi_initialize(av, philo);
        create_threads(philo);
    }
    else
        error("ERROR: number of arguments is not valide!\n");
    return (0);
}
