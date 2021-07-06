/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:24:42 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/06 20:55:21 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_trim_execname(char *argv_0)
{
	return (ft_strrchr(argv_0, '/') + 1);
}

int	ft_puterr(char *s)
{
	ft_putendl_fd(s, 2);
	return (1);
}

//	pthread_mutex_init(&simulation->main_thread, NULL);
static bool	init_mutexes(t_main *simulation)
{
	int	i;

	simulation->forks = (pthread_mutex_t *)
		ft_calloc(sizeof(pthread_mutex_t), simulation->config.count);
	if (!simulation->forks)
		return (false);
	i = -1;
	while (++i < simulation->config.count)
		pthread_mutex_init(&simulation->forks[i], NULL);
	pthread_mutex_init(&simulation->msg_queue, NULL);
	return (true);
}

static void	init_philosophers(t_main *simulation)
{
	int				i;
	t_philosopher	*philo;

	i = -1;
	philo = simulation->philosophers;
	while (++i < simulation->config.count)
	{
		philo[i].id = i;
		philo[i].main_struct = simulation;
		philo[i].left_fork = i;
		philo[i].right_fork = (i - 1 + simulation->config.count)
			% simulation->config.count;
		pthread_mutex_init(&philo[i].busy, NULL);
		pthread_mutex_init(&philo[i].just_ate, NULL);
		pthread_mutex_lock(&philo[i].just_ate);
	}
}

bool	simulation_init(t_main *simulation)
{
	simulation->philosophers = (t_philosopher *)
		ft_calloc(simulation->config.count, sizeof(t_philosopher));
	if (!simulation->philosophers)
		return (false);
	init_philosophers(simulation);
	return (init_mutexes(simulation));
}
