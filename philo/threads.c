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

void    my_print(char *ph, char *state, t_philo *philo)
{
    pthread_mutex_lock(philo->m_printf);
    printf(" %llu %s %d %s\n",(current_time() - philo->beginning_time), ph\
        ,philo->philo_index + 1, state);
    pthread_mutex_unlock(philo->m_printf);
}

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
        if (philo[i].eated == 0)
        {
            pthread_mutex_lock(philo[i].time);
            time = (current_time() - philo[i].time_of_start) -  philo[i].last_eat;
            pthread_mutex_unlock(philo[i].time);
            if(time >= philo[i].time_to_die && philo[i].eated == 0)
            {
                pthread_mutex_lock(philo[i].m_printf);
                printf(" %llu Philosopher %d dead\n",
                    (current_time() - philo[i].beginning_time),
                    philo[i].philo_index + 1);
                return ;
            }

        }
        pthread_mutex_unlock(philo->mutex);
        if(ac == 6)
            if (death_op_argument(philo) == 1)
                return ;
        i = (i + 1) % philo ->number_of_philos;
    }
}

void    *philorutin_1(void *philos)
{
    t_philo *philo;

    philo = (t_philo *)philos;
    while(1)
    {
        pthread_mutex_lock(&philo->fork[philo->philo_index]);
        my_print("Philosopher", "has taken a fork", philo);
        pthread_mutex_lock(&philo->fork[(philo->philo_index + 1) % philo->number_of_philos]);
        my_print("Philosopher", "has taken a fork", philo);
        my_print("Philosopher", "is eating", philo);
        pthread_mutex_lock(philo->mutex);
        philo->last_eat = current_time() - philo->time_of_start;
        pthread_mutex_unlock(philo->mutex);
        philo->numn_eat ++;
        pthread_mutex_lock(philo->mutex);
        philo->eated = 1;
        pthread_mutex_unlock(philo->mutex);
        sleeping(philo->time_to_eat);
        pthread_mutex_unlock(&philo->fork[philo->philo_index]);
        pthread_mutex_unlock(&philo->fork[(philo->philo_index + 1) % philo->number_of_philos]);
        pthread_mutex_lock(philo->mutex);
        philo->eated = 0;
        pthread_mutex_unlock(philo->mutex);
        my_print("Philosopher", "is sleeping", philo);
        sleeping(philo->time_to_sleep);
        my_print("Philosopher", "is thinking", philo);
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
        i += 2;
    }
    usleep(250);
    i = 1;
    while(i < number_of_philos)
    {
        if (pthread_create(&ph[i], NULL, philorutin_1, &philo[i]) != 0)
            error("ERROR\n");
        i += 2;
    }
    death(philo, ac);
    free(philo);
}