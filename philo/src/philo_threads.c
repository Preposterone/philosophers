/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:17:16 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/06 15:18:25 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(uint64_t time)
{
	uint64_t	wait_until;

	wait_until = get_current_time() + time;
	while (true)
	{
		usleep(USLEEP_GENERIC);
		if (get_current_time() >= wait_until)
			break ;
	}
}

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
			pthread_mutex_lock(&main_struct->philosophers[i].just_ate);
	}
	main_struct->party_over = true;
	dinner_over_message(main_struct, main_struct->config.eat_times);
	pthread_mutex_unlock(&main_struct->main_thread);
	return (NULL);
}

//			pthread_mutex_unlock(&philo->busy);
static void	*killer_job(void *philo_p)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philo_p;
	while (true)
	{
		pthread_mutex_lock(&philo->busy);
		if (!philo->is_eating && (int)(get_current_time() - philo->last_ate)
								 > philo->main_struct->config.tt_die)
		{
			philo->main_struct->party_over = true;
			simulation_message(philo, P_RED PHILO_DIED P_RESET, true);
			pthread_mutex_unlock(&philo->main_struct->main_thread);
			break ;
		}
		pthread_mutex_unlock(&philo->busy);
		usleep(USLEEP_GENERIC);
	}
	return (NULL);
}

//	philo->will_die_at = philo->last_ate + philo->main_struct->config.tt_die;
static void	*philosopher_job(void *philo_p)
{
	t_philosopher	*philo;
	pthread_t		id;

	philo = (t_philosopher *)philo_p;
	philo->last_ate = get_current_time();
	if (pthread_create(&id, NULL, &killer_job, philo_p) != 0)
		return (NULL);
	pthread_detach(id);
	while (!philo->main_struct->party_over)
	{
		philo_pick_up_forks(philo);
		philo_eat(philo);
		philo_drop_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

//		usleep(USLEEP_GENERIC);
bool	start_threads(t_main *simulation)
{
	int			i;
	pthread_t	id;
	void		*tmp;

	simulation->start_time = get_current_time();
	i = -1;
	if (simulation->config.eat_times > 0)
	{
		if (pthread_create(&id, NULL, &dinner_killer, simulation) != 0)
			return (NULL);
		pthread_detach(id);
		usleep(USLEEP_GENERIC);
	}
	while (++i < simulation->config.count)
	{
		tmp = (void *)&simulation->philosophers[i];
		if (pthread_create(&id, NULL, philosopher_job, tmp) != 0)
			return (false);
		pthread_detach(id);
		usleep(USLEEP_GENERIC);
	}
	return (true);
}
