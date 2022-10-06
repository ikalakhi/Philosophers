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
    while(i > philo_num)
    {
        pthread_create(&ph[i], NULL, &hey, NULL);
        i++;
    }
}

int main(int ac, char **av)
{
    int philo_num;

    philo_num = ft_atoi(av[1]);
    if (ac >= 1)
    {
        check_numbers(av);
        create_threads(philo_num);
    }
    else
        error("ERROR: arguments are not valide!\n");
    return (0);
}