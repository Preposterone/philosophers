/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:24:33 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/09 14:27:30 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(uint64_t time)
{
	uint64_t	wait_until;

	wait_until = get_current_time() + time;
	while (true)
	{
		usleep(USLEEP_SHORT);
		if (get_current_time() >= wait_until)
			break ;
	}
}

static void	cleanup(t_main *simulation)
{
	int	i;

	i = -1;
	while (++i < simulation->config.count)
		kill(simulation->philosophers->pid, SIGKILL);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_MESSAGE);
	sem_unlink(SEM_MAIN_THREAD);
	if (simulation->philosophers)
	{
		i = -1;
		while (++i < simulation->config.count)
		{
			sem_unlink(simulation->philosophers[i].sem_just_ate_name);
			sem_unlink(simulation->philosophers[i].s_busy);
			free(simulation->philosophers[i].sem_just_ate_name);
			free(simulation->philosophers[i].s_busy);
		}
		free(simulation->philosophers);
	}
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

	memset(&main_struct, 0, sizeof(t_main));
	ret = 0;
	if (!ft_parse_args(argc, &argv[1], &main_struct.config))
		ret = ft_incorrect_args(argv[0]);
	else if (!simulation_init(&main_struct))
		ret = ft_puterr("Fatal error! Malloc failed!");
	else if (!start_threads(&main_struct))
		ret = ft_puterr("Fatal error! Couldn't start threads!");
	else if (!start_processes(&main_struct))
		 ret = ft_puterr("Fatal error! Couldn't start processes!");
	else
		sem_wait(main_struct.main_thread);
	cleanup(&main_struct);
	return (ret);
}
