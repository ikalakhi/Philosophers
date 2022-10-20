/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:29:23 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/10/18 11:29:25 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void    *philorutin_1(void *philos)
{
    t_philo *philo;

    philo = (t_philo *)philos;
    while(1)
    {
        pthread_mutex_lock(&philo->fork[philo->philo_index]);
        pthread_mutex_lock(philo->m_printf);
        printf("%llu Philosopher %d has taken a fork\n",\
            (current_time() - philo->beginning_time) ,philo->philo_index + 1);
        pthread_mutex_unlock(philo->m_printf);
        pthread_mutex_lock(&philo->fork[(philo->philo_index + 1) % philo->number_of_philos]);
        pthread_mutex_lock(philo->m_printf);
        printf("%llu Philosopher %d has taken a fork\n",\
            (current_time() - philo->beginning_time), philo->philo_index + 1);
        pthread_mutex_unlock(philo->m_printf);
        pthread_mutex_lock(philo->m_printf);
        printf("Philosopher %d is eating\n", philo->philo_index + 1);
        pthread_mutex_unlock(philo->m_printf);
        sleeping(philo->time_to_sleep);
        pthread_mutex_unlock(&philo->fork[philo->philo_index]);
        pthread_mutex_unlock(&philo->fork[(philo->philo_index + 1) % philo->number_of_philos]);
        pthread_mutex_lock(philo->m_printf);
        printf("Philosopher %d is taking a nap\n", philo->philo_index + 1);
        pthread_mutex_unlock(philo->m_printf);
    }
}

void    create_threads(t_philo *philo, int number_of_philos)
{
    int         i;
    pthread_t   *ph;

    i = 0;
    ph = malloc(sizeof(pthread_t) * number_of_philos);
    if (!ph)
       return ;
    while(i < number_of_philos)
    {
        if (pthread_create(&ph[i], NULL, philorutin_1, &philo[i]) != 0)
            error("ERROR\n");
        usleep(100);
        i++;
    }
}
