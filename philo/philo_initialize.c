/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:43:08 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/10/20 18:43:34 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void    forkes_initialize(t_philo *philo, int num_philo)
{
    int i;
    pthread_mutex_t *mutex;
    pthread_mutex_t *mutex_printf;

    i = 0;
    mutex = malloc(sizeof(pthread_mutex_t) * num_philo);
    mutex_printf = malloc(sizeof(pthread_mutex_t));
    // pthread_mutex_init(mutex_printf, NULL);
    while(i < num_philo)
    {
        pthread_mutex_init(&mutex[i], NULL);
        i++;
    }
    i = 0;
    while(i < num_philo)
    {
        philo[i].fork = mutex;
        philo[i].m_printf = mutex_printf;
        i++;
    }
}