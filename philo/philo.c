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

void    *hey()
{
    void    *i = NULL;

    printf("I am here\n");
    return(i);
}

void    create_threads(int philo_num)
{
    pthread_t   ph[philo_num];
    int         i;

    i = 0;
    while(i < philo_num)
    {
        if (pthread_create(&ph[i], NULL, &hey, NULL) != 0)
            error("ERROR\n");
        usleep(1);
        i++;
    }
}

int main(int ac, char **av)
{
    int philo_num;

    if (ac > 1)
    {
        philo_num = ft_atoi(av[1]);
        check_numbers(av);
        create_threads(philo_num);
    }
    else
        error("ERROR: arguments are not valide!\n");
    return (0);
}
