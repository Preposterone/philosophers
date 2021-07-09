/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:17:16 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/09 14:22:27 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*dinner_killer(void *main_p)
{
	t_main	*main_struct;
	int		i;
	int		ate_times;

	main_struct = (t_main *)main_p;
	ate_times = -1;
	while (++ate_times < main_struct->config.eat_times)
	{
		i = -1;
		while (++i < main_struct->config.count)
			sem_wait(main_struct->philosophers[i].just_ate);
	}
	dinner_over_message(main_struct, main_struct->config.eat_times);
	sem_post(main_struct->main_thread);
	return (NULL);
}

static void	*killer_job(void *philo_p)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philo_p;
	while (true)
	{
		sem_wait(philo->busy);
		if (!philo->is_eating && (int)(get_current_time() - philo->last_ate)
								 > philo->main_struct->config.tt_die)
		{
			simulation_message(philo, P_RED PHILO_DIED P_RESET, true);
			sem_post(philo->main_struct->main_thread);
			break ;
		}
		sem_post(philo->busy);
		usleep(USLEEP_LONG);
	}
	return (NULL);
}

static int	philosopher_process(t_philosopher *philo)
{
	pthread_t		id;

	philo->last_ate = get_current_time();
	if (pthread_create(&id, NULL, &killer_job, (void *)philo) != 0)
		return (1);
	pthread_detach(id);
	while (true)
	{
		philo_pick_up_forks(philo);
		philo_eat(philo);
		philo_drop_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (0);
}

bool	start_threads(t_main *simulation)
{
	pthread_t	id;

	if (simulation->config.eat_times > 0)
	{
		if (pthread_create(&id, NULL, &dinner_killer, simulation) != 0)
			return (NULL);
		pthread_detach(id);
	}
	return (true);
}

bool	start_processes(t_main *simulation)
{
	int	i;

	simulation->start_time = get_current_time();
	i = -1;
	while (++i < simulation->config.count)
	{
		simulation->philosophers[i].pid = fork();
		if (simulation->philosophers[i].pid < 0)
			return (false);
		else if (simulation->philosophers[i].pid == 0)
			exit(philosopher_process(&simulation->philosophers[i]));
		else
			usleep(USLEEP_SHORT);
	}
	return (true);
}
