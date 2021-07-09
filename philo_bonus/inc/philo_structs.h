/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:24:37 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/09 13:12:03 by aarcelia         ###   ########.fr       */
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
# include <semaphore.h>

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
	struct s_main	*main_struct;
	pid_t			pid;
	sem_t			*busy;
	char			*s_busy;
	sem_t			*just_ate;
	char			*sem_just_ate_name;
}				t_philosopher;

typedef struct s_main
{
	t_config		config;
	uint64_t		start_time;
	t_philosopher	*philosophers;
	sem_t			*forks;
	sem_t			*msg_queue;
	sem_t			*main_thread;
}				t_main;

#endif
