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

/*void	simulation_message(t_philosopher *philo, char *msg, bool death)
{
	uint64_t timestamp;

	pthread_mutex_lock(&philo->main_struct->msg_queue);
	timestamp = get_elapsed_time(philo->main_struct->start_time);
	printf("[" "%6llu ms" "]: Philosopher [%d]\t[%s]\n",
		   timestamp, philo->id + 1, msg);
	if (!death)
		pthread_mutex_unlock(&philo->main_struct->msg_queue);
}*/

void	simulation_message(t_philosopher *philo, char *msg, bool death)
{
	uint64_t	timestamp;

	pthread_mutex_lock(&philo->main_struct->msg_queue);
	timestamp = get_elapsed_time(philo->main_struct->start_time);
	ft_putstr_fd("[" P_YELLOW, 1);
	ft_putnllu_fd(timestamp, 1);
	ft_putstr_fd("ms" P_RESET "]: Philosopher [", 1);
	ft_putnbr_fd(philo->id + 1, 1);
	ft_putstr_fd("]\t[", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("]\n", 1);
	if (!death)
		pthread_mutex_unlock(&philo->main_struct->msg_queue);
}

/*
void	simulation_message(t_philosopher *philo, char *msg)
{
	static char	buf[BUF_WIDTH];
	static char	num[20];
	uint64_t	timestamp;
	int			i;

	pthread_mutex_lock(&philo->main_struct->msg_queue);
	memset(buf, 0, BUF_WIDTH);
	memset(num, 0, 20);
	//[ TIMESTAMP ]: Philosopher [...]/t [action]\n
	//[ 20 ]: Philosopher [5]/t[action]\n
	timestamp = get_elapsed_time(philo->main_struct->start_time);
	i = -1;
	while(++i)
	{
		;
	}
	pthread_mutex_unlock(&philo->main_struct->msg_queue);
}
*/
