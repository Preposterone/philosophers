#ifndef PHILO_H
# define PHILO_H

#include "philo_structs.h"
#include "libft.h"
#include <stdio.h>

/*=================================FUNCTIONS==================================*/
bool	ft_is_all_digits(char **argv);
void	ft_parse_config(char **argv, t_philo_config *config);
bool	ft_parse_args(int argc, char **argv, t_philo_config *config);

# define USG "<num_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>"
# define USG_OPT " (OPTIONAL)[number_of_times_each_philosopher_must_eat]"
# define DESC ""

#endif
