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

int death_op_argument(t_philo *philo)
{
    int cont;

    cont = 0;
    while(cont < philo->number_of_philos)
    {
        if (philo[cont].numn_eat < philo ->op_argument)
            return (0);
        cont++;
    }
    return(1);
}

void    death(t_philo *philo, int ac)
{
    int         i;
    long long   time;

    i = 0;
    while(i < philo->number_of_philos)
    {
        pthread_mutex_lock(philo->mutex);
        if (philo->number_of_philos == 1)
        {   pthread_mutex_lock(philo[i].m_printf);
            printf(" %llu  %d dead\n",
                (current_time() - philo[i].beginning_time),
                philo[i].philo_index + 1);
                return ;
        }
        if (philo[i].eated == 0)
        {
            pthread_mutex_lock(philo[i].time);
            time = (current_time() - philo[i].time_of_start) -  philo[i].last_eat;
            pthread_mutex_unlock(philo[i].time);
            if(time >= philo[i].time_to_die && philo[i].eated == 0)
            {
                pthread_mutex_lock(philo[i].m_printf);
                printf(" %llu  %d dead\n",
                    (current_time() - philo[i].beginning_time),
                    philo[i].philo_index + 1);
                return ;
            }

        }
        pthread_mutex_unlock(philo->mutex);
        if(ac == 6)
        {
            pthread_mutex_lock(philo[i].time);
            if (death_op_argument(philo) == 1)
                return ;
            pthread_mutex_unlock(philo[i].time);
        }
        i = (i + 1) % philo ->number_of_philos;
    }
}

void    help_rutin(t_philo *philo)
{
    sleeping(philo->time_to_eat);
    pthread_mutex_unlock(&philo->fork[philo->philo_index]);
    pthread_mutex_unlock(&philo->fork[(philo->philo_index + 1) % philo->number_of_philos]);
    pthread_mutex_lock(philo->mutex);
    philo->eated = 0;
    pthread_mutex_unlock(philo->mutex);
    my_print("is sleeping", philo);
    sleeping(philo->time_to_sleep);
    my_print("is thinking", philo);
}

void    *philorutin_1(void *philos)
{
    t_philo *philo;

    philo = (t_philo *)philos;
    while(1)
    {
        pthread_mutex_lock(&philo->fork[philo->philo_index]);
        my_print("has taken a fork", philo);
        pthread_mutex_lock(&philo->fork[(philo->philo_index + 1) % philo->number_of_philos]);
        my_print("has taken a fork", philo);
        my_print("is eating", philo);
        pthread_mutex_lock(philo->mutex);
        philo->last_eat = current_time() - philo->time_of_start;
        pthread_mutex_unlock(philo->mutex);
        philo->numn_eat ++;
        pthread_mutex_lock(philo->mutex);
        philo->eated = 1;
        pthread_mutex_unlock(philo->mutex);
        help_rutin(philo);
    }
}

void    create_threads(t_philo *philo, int number_of_philos, int ac)
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
        usleep(150);
        i++;
    }
    death(philo, ac);
    free(ph);
}