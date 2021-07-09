/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:24:42 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/09 14:21:54 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_puterr(char *s)
{
	ft_putendl_fd(s, 2);
	return (1);
}

static bool	init_semaphores(t_main *main_struct)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MAIN_THREAD);
	sem_unlink(SEM_MESSAGE);
	main_struct->forks = sem_open(SEM_FORKS, O_CREAT | O_EXCL, 0644,
			main_struct->config.count);
	if (main_struct->forks == SEM_FAILED)
		return (false);
	main_struct->msg_queue = sem_open(SEM_MESSAGE, O_CREAT | O_EXCL, 0644, 1);
	if (main_struct->msg_queue == SEM_FAILED)
		return (false);
	main_struct->main_thread = sem_open(SEM_MAIN_THREAD, O_CREAT | O_EXCL,
			0644, 0);
	if (main_struct->main_thread == SEM_FAILED)
		return (false);
	return (true);
}

static bool	init_philosophers(t_main *simulation)
{
	int				i;
	t_philosopher	*philo;
	char			*index;

	i = -1;
	philo = simulation->philosophers;
	while (++i < simulation->config.count)
	{
		philo[i].id = i;
		philo[i].main_struct = simulation;
		index = ft_itoa(i);
		philo[i].s_busy = ft_strjoin(SEM_BUSY, index);
		sem_unlink(philo[i].s_busy);
		philo[i].busy = sem_open(philo[i].s_busy, O_CREAT | O_EXCL, 0644, 1);
		philo[i].sem_just_ate_name = ft_strjoin(SEM_JUST_ATE, index);
		sem_unlink(philo[i].sem_just_ate_name);
		philo[i].just_ate = sem_open(philo[i].sem_just_ate_name,
				O_CREAT | O_EXCL, 0644, 0);
		if (philo[i].busy == SEM_FAILED || philo[i].just_ate == SEM_FAILED)
			return (false);
		free(index);
	}
	return (true);
}

bool	simulation_init(t_main *simulation)
{
	simulation->philosophers = (t_philosopher *)
		ft_calloc(simulation->config.count, sizeof(t_philosopher));
	if (!simulation->philosophers)
		return (false);
	if (!init_philosophers(simulation))
		return (false);
	return (init_semaphores(simulation));
}
