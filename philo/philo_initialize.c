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
    pthread_mutex_t *mutex_protect;

    i = 0;
    mutex = malloc(sizeof(pthread_mutex_t) * num_philo);
    mutex_printf = malloc(sizeof(pthread_mutex_t));
    mutex_protect = malloc(sizeof(pthread_mutex_t));
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
        philo[i].mutex = mutex_protect;
        i++;
    }
}

void	atoi_initialize(char **av, t_philo *philo)
{
	int	num_philo;
	int	i;

	num_philo = ft_atoi(av[1]);
	i = 0;
	while(i < num_philo)
	{
		philo[i].number_of_philos = ft_atoi(av[1]);
		philo[i].beginning_time = current_time();
		philo[i].time_to_sleep = ft_atoi(av[4]);
		philo[i].time_to_die = ft_atoi(av[2]);
		philo[i].time_to_eat = ft_atoi(av[3]);
        philo[i].time_of_now = current_time();
		philo[i].philo_index = i;
		philo[i].death = 0;
        philo[i].numn_eat = 0;
        philo[i].last_eat = 0;
		i++;
	}
}