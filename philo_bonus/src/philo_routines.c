/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:45:53 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/09 13:36:45 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//TODO: redo
void	philo_eat(t_philosopher *philo)
{
	sem_wait(philo->busy);
	philo->is_eating = true;
	philo->last_ate = get_current_time();
	simulation_message(philo, P_GREEN PHILO_EATING P_RESET, false);
	ft_usleep(philo->main_struct->config.tt_eat);
	philo->is_eating = false;
	sem_post(philo->busy);
	sem_post(philo->just_ate);
}

//TODO: redo
void	philo_drop_forks(t_philosopher *philo)
{
	sem_post(philo->main_struct->forks);
	sem_post(philo->main_struct->forks);
}

//TODO: redo
void	philo_sleep(t_philosopher *philo)
{
	simulation_message(philo, PHILO_SLEEPING, false);
	ft_usleep(philo->main_struct->config.tt_sleep);
}

//TODO: redo
void	philo_think(t_philosopher *philo)
{
	simulation_message(philo, PHILO_THINKING, false);
}

//TODO: redo
void	philo_pick_up_forks(t_philosopher *philo)
{
	sem_wait(philo->main_struct->forks);
	simulation_message(philo, PHILO_FORK, false);
	sem_wait(philo->main_struct->forks);
	simulation_message(philo, PHILO_FORK, false);
}
