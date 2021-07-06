/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:24:33 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/06 20:52:53 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleanup(t_main *simulation)
{
	int	i;

	if (simulation->forks)
	{
		i = -1;
		while (++i < simulation->config.count)
			pthread_mutex_destroy(&simulation->forks[i]);
		free(simulation->forks);
	}
	if (simulation->philosophers)
	{
		i = -1;
		while (++i < simulation->config.count)
		{
			pthread_mutex_destroy(&simulation->philosophers[i].busy);
			pthread_mutex_destroy(&simulation->philosophers[i].just_ate);
		}
		free(simulation->philosophers);
	}
	pthread_mutex_destroy(&simulation->msg_queue);
	pthread_mutex_destroy(&simulation->main_thread);
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
int	main(int argc, char *argv[])
{
	t_main	main_struct;
	int		ret;

	ft_bzero(&main_struct, sizeof(t_main));
	pthread_mutex_init(&main_struct.main_thread, NULL);
	pthread_mutex_lock(&main_struct.main_thread);
	ret = 0;
	if (!ft_parse_args(argc, &argv[1], &main_struct.config))
		ret = ft_incorrect_args(argv[0]);
	else if (!simulation_init(&main_struct))
		ret = ft_puterr("Fatal error! Malloc failed!");
	else if (!start_threads(&main_struct))
		ret = ft_puterr("Fatal error! Couldn't start threads!");
	else
		pthread_mutex_lock(&main_struct.main_thread);
	pthread_mutex_unlock(&main_struct.main_thread);
	cleanup(&main_struct);
	return (ret);
}
