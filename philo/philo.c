#include "philo.h"

void    create_threads(char *av)
{
    int philo_num;

    philo_num = ft_atoi(av);
    while(philo_num > 0)
    {
         
    }
}

int main(int ac, char **av)
{
    //creat threads in number of av[1]
    if (ac >= 5 && ac <= 6)
    {
        create_threads(av[1]);
    }
}