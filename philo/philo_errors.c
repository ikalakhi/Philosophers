/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:39:02 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/10/07 09:39:04 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	return ;
}

int	check_emty_string(char **av)
{
	int	i;
	int	j;

	i = 0;
	while(av[i])
	{
		j = 0;
		while(av[i][j + 1])
		{
			if (!av[i][j])
			{
                error("ERROR: arguments are not valide!\n");
				return (-1);
			}
            j++;
		}
        i++;
	}
	return (0);
}

int	check_numbers(char **av)
{
	int	i;
	int	j;

	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if(av[i][0] == '+')
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
            {
                error("ERROR: arguments are not valide!\n");
				return (-1);
			}
            j++;
		}
        i++;
	}
	return(0);
}
