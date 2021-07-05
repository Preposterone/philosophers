/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:29:19 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/05 17:29:29 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulation_message(t_philosopher *philo, char *msg)
{
	uint64_t timestamp;

	pthread_mutex_lock(&philo->main_struct->msg_queue);
	timestamp = get_elapsed_time(philo->main_struct->start_time);
	printf("[" P_YELLOW "%6llu ms" P_RESET "]: Philosopher [%d]\t[%s]\n",
		   timestamp, philo->id + 1, msg);
	pthread_mutex_unlock(&philo->main_struct->msg_queue);
}
