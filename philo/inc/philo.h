/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:24:20 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/05 11:24:20 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_structs.h"
# include "libft.h"
# include <stdio.h>

/*=================================FUNCTIONS==================================*/
bool		ft_parse_args(int argc, char **argv, t_config *config);
bool		simulation_init(t_main *simulation);
int			ft_puterr(char *s);
int			ft_incorrect_args(char *argv_0);
char		*ft_trim_execname(char *argv_0);
void		simulation_message(t_philosopher *philo, char *msg);
void		philo_pick_up_forks(t_philosopher *philo);
void		philo_eat(t_philosopher *philo);
void		philo_drop_forks(t_philosopher *philo);
void		philo_sleep(t_philosopher *philo);
void		philo_think(t_philosopher *philo);
uint64_t	get_current_time(void);
uint64_t	get_elapsed_time(uint64_t start_time);

/*=================================CONSTANTS==================================*/
# define USG "<num_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>"
# define USG_OPT " (OPTIONAL)[number_of_times_each_philosopher_must_eat]"
# define DESC ""
# define PHILO_FORK "has taken a fork."
# define PHILO_EATING "is eating."
# define PHILO_SLEEPING "is eating."
# define PHILO_THINKING "is thinking."
# define PHILO_DIED "has died."
# define P_GREEN   "\x1b[92m"
# define P_RED   "\x1b[91m"
# define P_YELLOW   "\x1b[33m"
# define P_RESET   "\x1b[0m"
# ifndef USLEEP_GENERIC
#  define USLEEP_GENERIC 100
# endif

#endif
