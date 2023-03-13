/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:38:33 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/10/22 14:12:38 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_comp	*comp;
	int		num_philo;

	if (ac == 5 || ac == 6)
	{
		if (check_numbers(av) == -1 || check_emty_string(av) == -1)
			return (0);
		num_philo = ft_atoi(av[1]);
		if (num_philo <= 0)
		{
			error("ERROR:  arguments is not valide!\n");
			return (0);
		}
		comp = malloc(sizeof(t_comp) * 1);
		philo = malloc(sizeof(t_philo) * num_philo);
		if (!comp || !philo)
			return (0);
		atoi_initialize(av, philo, ac);
		forkes_initialize(philo, num_philo);
		create_threads(philo, num_philo, ac);
	}
	else
		error("ERROR: number of arguments is not valide!\n");
	return (0);
}
