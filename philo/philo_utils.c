/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:39:12 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/10/07 09:39:14 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int			s;
	int			i;
	long int	nb;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++ ;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * (-1);
		i++;
	}
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb > 2147483647 && s > 0)
			return (-1);
		else if (nb > 2147483648 && s < 0)
			return (0);
		i++ ;
	}
	return (s * nb);
}

void	atoi_initialize(char **av, t_philo *philo)
{
	philo->number_of_philo = ft_atoi(av[1]);
	printf("number_of_philo %d\n", philo->number_of_philo);
	philo->time_to_die = ft_atoi(av[2]);
	printf("time_to_die %d\n", philo->time_to_die);
	philo->time_to_eat = ft_atoi(av[3]);
	printf("time_to_eat %d\n", philo->time_to_eat);
	philo->time_to_sleep = ft_atoi(av[4]);
	printf("time_to_sleep %d\n", philo->time_to_sleep);
}