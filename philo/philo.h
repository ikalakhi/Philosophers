
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
}   t_philo;


void	error(char *s);
void	check_numbers(char **av);
void    create_threads(int philo_num);

int     ft_atoi(char *str);

#endif