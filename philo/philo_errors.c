#include "philo.h"

void	error(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	check_numbers(char **av)
{
	int	i;
	int	j;

	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
                error("ERROR: arguments are not valide!\n");
            j++;
		}
        i++;
	}
}