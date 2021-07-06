/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:23:51 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/05 15:23:53 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((uint64_t)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

uint64_t	get_elapsed_time(uint64_t start_time)
{
	return (get_current_time() - start_time);
}
