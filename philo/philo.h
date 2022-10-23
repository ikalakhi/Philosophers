/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:38:48 by ikalakhi          #+#    #+#             */
/*   Updated: 2022/10/22 14:18:15 by ikalakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <sys/wait.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_struct
{
	long long	time_of_now;
}	t_comp;

typedef struct t_philosophers
{
	int				philo_index;
	int				time_to_die;
	int				time_to_eat;
	int				number_of_philos;
	int				death;
	int				numn_eat;
	int				op_argument;
	int				eated;
	long long		last_eat;
	long long		time_of_start;
	long long		time_to_sleep;
	long long		current_time;
	long long		beginning_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*time;
	pthread_mutex_t	*m_printf;
}	t_philo;

void		error(char *s);
void		death(t_philo *philo, int ac);
void		sleeping(long long time_to_sleep);
void		my_print(char *state, t_philo *philo);
void		forkes_initialize(t_philo *philo, int num_philo);
void		atoi_initialize(char **av, t_philo *philo, int ac);
void		create_threads(t_philo *philo, int number_of_philos, int ac);

int			check_numbers(char **av);
int			check_emty_string(char **av);
int			ft_atoi(char *str);

long long	current_time(void);

#endif
