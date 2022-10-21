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
	exit(EXIT_FAILURE);
}

void check_emty_string(char **av)
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
                error("ERROR: arguments are not valide!\n");
            j++;
		}
        i++;
	}
}

void	check_numbers(char **av)
{
	int	i;
	int	j;

	i = 1;
	check_emty_string(av);
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
