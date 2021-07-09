/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:29:19 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/09 13:28:20 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	return (memset(ret, 0, count * size));
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

void	dinner_over_message(t_main *main_struct, int times)
{
	unsigned long long	timestamp;

	sem_wait(main_struct->msg_queue);
	timestamp = get_elapsed_time(main_struct->start_time);
	printf("[" P_YELLOW "%6llu ms" P_RESET "]: Dinner's over! "
		"Everyone ate at least '%d' times\n", timestamp, times);
}

void	simulation_message(t_philosopher *philo, char *msg, bool death)
{
	unsigned long long	timestamp;

	sem_wait(philo->main_struct->msg_queue);
	timestamp = get_elapsed_time(philo->main_struct->start_time);
	printf("[" P_YELLOW "%6llu ms" P_RESET "]: Philosopher [%d]\t[%s]\n",
		   timestamp, philo->id + 1, msg);
	if (!death)
		sem_post(philo->main_struct->msg_queue);
}

/*
void	dinner_over_message(t_main *main_struct, int times)
{
	uint64_t	timestamp;

	pthread_mutex_lock(&main_struct->msg_queue);
	timestamp = get_elapsed_time(main_struct->start_time);
	ft_putstr_fd("[" P_YELLOW, 1);
	ft_putnllu_fd(timestamp, 1);
	ft_putstr_fd(" ms" P_RESET "]: Dinner's over! Everyone ate at least '", 1);
	ft_putnbr_fd(times, 1);
	ft_putstr_fd("' times!\n", 1);
}

void	simulation_message(t_philosopher *philo, char *msg, bool death)
{
	uint64_t	timestamp;

	pthread_mutex_lock(&philo->main_struct->msg_queue);
	timestamp = get_elapsed_time(philo->main_struct->start_time);
	ft_putstr_fd("[" P_YELLOW, 1);
	ft_putnllu_fd(timestamp, 1);
	ft_putstr_fd(" ms" P_RESET "]: Philosopher [", 1);
	ft_putnbr_fd(philo->id + 1, 1);
	ft_putstr_fd("]\t[", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("]\n", 1);
	if (!death)
		pthread_mutex_unlock(&philo->main_struct->msg_queue);
}
*/
