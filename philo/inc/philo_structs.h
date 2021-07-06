/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:24:37 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/05 11:24:37 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

# include <sys/types.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>
# include <stdint.h>
# include <pthread.h>

/*
 * count - number of philisophers
 * tt_die - time to die in ms
 * tt_eat - time to eat in ms
 * tt_sleep - time to sleep in ms
 * eat_times - [OPTIONAL] number of times each philosopher must eat
*/
typedef struct s_config
{
	int	count;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	eat_times;
}				t_config;

/*
 * Struct for each philosopher
*/
typedef struct s_philosopher
{
	int				id;
	bool			is_eating;
	uint64_t		last_ate;
	int				left_fork;
	int				right_fork;
	struct s_main	*main_struct;
	pthread_mutex_t	just_ate;
	pthread_mutex_t	busy;
}				t_philosopher;

typedef struct s_main
{
	t_config		config;
	uint64_t		start_time;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg_queue;
	pthread_mutex_t	main_thread;
}				t_main;

#endif
