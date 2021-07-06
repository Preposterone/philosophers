/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:45:53 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/05 17:45:55 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_pick_up_forks(t_philosopher *philo)
{
	simulation_message(philo, PHILO_FORK, false);
	pthread_mutex_lock(&philo->main_struct->forks[philo->right_fork]);
	simulation_message(philo, PHILO_FORK, false);
	pthread_mutex_lock(&philo->main_struct->forks[philo->left_fork]);
}

void	philo_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->busy);
	philo->is_eating = true;
	philo->last_ate = get_current_time();
	simulation_message(philo, P_GREEN PHILO_EATING P_RESET, false);
	ft_usleep(philo->main_struct->config.tt_eat);
	philo->is_eating = false;
	pthread_mutex_unlock(&philo->busy);
	pthread_mutex_unlock(&philo->just_ate);
}

void	philo_drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->main_struct->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->main_struct->forks[philo->left_fork]);
}

void	philo_sleep(t_philosopher *philo)
{
	simulation_message(philo, PHILO_SLEEPING, false);
	ft_usleep(philo->main_struct->config.tt_sleep);
}

void	philo_think(t_philosopher *philo)
{
	simulation_message(philo, PHILO_THINKING, false);
}
