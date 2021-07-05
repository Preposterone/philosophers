/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:24:33 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/05 11:24:33 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *killer_job(void *philo_p)
{
	t_philosopher *philo;

	philo = (t_philosopher *)philo_p;
	while (true)
	{
		pthread_mutex_lock(&philo->busy);
		if (!philo->is_eating && get_current_time() > philo->will_die_at)
		{
			simulation_message(philo, P_RED PHILO_DIED P_RESET);
			pthread_mutex_unlock(&philo->busy);
			pthread_mutex_unlock(&philo->main_struct->main_thread); //to exit in main
			return (NULL);
		}
		pthread_mutex_unlock(&philo->busy);
		usleep(1000);
	}
	return (NULL);
}

void *philosopher_job(void *philo_p)
{
	t_philosopher	*philo;
	pthread_t		tid;

	philo = (t_philosopher *)philo_p;
	philo->last_ate = get_current_time();
	philo->will_die_at = philo->last_ate + philo->main_struct->config.tt_die;
	if (pthread_create(&tid, NULL, &killer_job, philo_p) != 0)
		return (NULL);
	while (true)
	{
		//pick_up_forks
		philo_pick_up_forks(philo);
		//eat
		philo_eat(philo);
		//drop forks
		philo_drop_forks(philo);
		//sleep
		philo_sleep(philo);
		//think
		philo_think(philo);
	}
	return (NULL);
}

static bool start_threads(t_main *simulation)
{
	int			i;
	pthread_t	tid;
	void		*tmp;

	simulation->start_time = get_current_time();
	i = -1;
	while (++i < simulation->config.count)
	{
		tmp = (void *)&simulation->philosophers[i];
		if (pthread_create(&tid, NULL, &philosopher_job, tmp) != 0)
			return (false);
		pthread_detach(tid);
		usleep(USLEEP_GENERIC);
	}
	return (true);
}

/**
 * Several philosophers are sitting at a round table doing one of three things:
 * eating, thinking, or sleeping.
 * While eating, they are not thinking or sleeping,
 * while sleeping, they are not eating or thinking and of course,
 * while thinking, they are not eating or sleeping.
 * @param argv: philo_amount time_to_die time_to_eat time_to_sleep eat_times
 * each parameter has to be '0 < parameter <= INT_MAX'
 */
int main (int argc, char *argv[])
{
	t_main	main_struct;
	int		ret;

	ft_bzero(&main_struct, sizeof(t_main));
	pthread_mutex_init(&main_struct.main_thread, NULL);
	pthread_mutex_lock(&main_struct.main_thread);
	ret = 0;
	if (!ft_parse_args(argc, &argv[1], &main_struct.config)){
		ret = ft_incorrect_args(argv[0]);
	}
	else if (!simulation_init(&main_struct)) {
		ret = ft_puterr("Fatal error! Malloc failed!");
	}
	else if (!start_threads(&main_struct)) {
		ret = ft_puterr("Fatal error! Couldn't start threads!");
	}
	else
		pthread_mutex_lock(&main_struct.main_thread);	//endless loop
	pthread_mutex_unlock(&main_struct.main_thread);
	//cleanup, dealloc
	return (ret);
}
