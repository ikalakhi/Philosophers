/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:30:17 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/10/20 16:30:43 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void    my_print(char *state, t_philo *philo)
{
    pthread_mutex_lock(philo->m_printf);
    printf(" %llu  %d %s\n",(current_time() - philo->beginning_time)\
        ,philo->philo_index + 1, state);
    pthread_mutex_unlock(philo->m_printf);
}

long long   current_time(void)
{
    struct timeval time;
    long long       i;

    gettimeofday(&time, NULL);
    i = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return(i);
}

void    sleeping(long long time_to_sleep)
{
    long long  time_now;

    time_now = current_time();
    while(current_time() - time_now < time_to_sleep)
        usleep(150);
}

void    my_free(t_philo *philo)
{
    free(philo->m_printf);
    free(philo->mutex);
    free(philo->fork);
    free(philo);
}