
#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

# include <sys/types.h>
# include <stdbool.h>
# include <limits.h>

/**
 * count - number of philisophers
 * tt_die - time to die in ms
 * tt_eat - time to eat in ms
 * tt_sleep - time to sleep in ms
 * eat_times - [OPTIONAL] number of times each philosopher must eat
 */

typedef struct s_philo_config
{
	int	count;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	eat_times;
}	t_philo_config;

#endif
