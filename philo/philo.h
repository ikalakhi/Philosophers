
#ifndef PHILO_H
# define PHILO_H

#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void    create_threads(char *av);
int     ft_atoi(char *str);

#endif