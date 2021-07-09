/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:24:20 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/09 13:49:33 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_structs.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

/*=================================FUNCTIONS==================================*/
bool		ft_parse_args(int argc, char **argv, t_config *config);
bool		simulation_init(t_main *simulation);
int			ft_puterr(char *s);
int			ft_incorrect_args(char *argv_0);
char		*ft_trim_execname(char *argv_0);
void		simulation_message(t_philosopher *philo, char *msg, bool death);
void		philo_pick_up_forks(t_philosopher *philo);
void		philo_eat(t_philosopher *philo);
void		philo_drop_forks(t_philosopher *philo);
void		philo_sleep(t_philosopher *philo);
void		philo_think(t_philosopher *philo);
uint64_t	get_current_time(void);
uint64_t	get_elapsed_time(uint64_t start_time);
void		ft_usleep(uint64_t time);
bool		start_threads(t_main *simulation);
void		dinner_over_message(t_main *main_struct, int times);
bool		start_processes(t_main *simulation);

/*==============================LIBFT FUNCTIONS===============================*/
size_t		ft_strlen(const char *s);
char		*ft_strrchr(const char *s, int c);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
int64_t		ft_atoll(char *s);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);
/*=================================CONSTANTS==================================*/
# define USG "<num_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>"
# define USG_OPT " (OPTIONAL)[number_of_times_each_philosopher_must_eat]"
# define DESC ""
# define PHILO_FORK "has taken a fork."
# define PHILO_EATING "is eating."
# define PHILO_SLEEPING "is sleeping."
# define PHILO_THINKING "is thinking."
# define PHILO_DIED "has died."
# define P_GREEN   "\x1b[92m"
# define P_RED   "\x1b[91m"
# define P_YELLOW   "\x1b[33m"
# define P_RESET   "\x1b[0m"
# define USLEEP_SHORT 100
# define USLEEP_LONG 1000
/*Global semaphores*/
# define SEM_FORKS "SEMAPHORE_FORKS"
# define SEM_MESSAGE "SEMAPHORE_MESSAGE_QUEUE"
# define SEM_MAIN_THREAD "SEMAPHORE_MAIN_THREAD"
/*Individual semaphores*/
# define SEM_BUSY "SEMAPHORE_PHILO_BUSY_"
# define SEM_JUST_ATE "SEMAPHORE_PHILO_JUST_ATE_"

#endif
