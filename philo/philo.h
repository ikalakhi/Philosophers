/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:38:48 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/10/07 09:38:54 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct t_philosophers
{
    int i;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_philos;
}   t_philo;

void    error(char *s);
void    check_numbers(char **av);
void    create_threads(t_philo *philo);
void	atoi_initialize(char **av, t_philo *philo);

int     ft_atoi(char *str);

#endif
