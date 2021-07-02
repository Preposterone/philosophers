
#include "philo.h"

static char *ft_trim_execname(char *argv_0)
{
	return (ft_strrchr(argv_0, '/') + 1);
}

static void print_usage(char *exec_name)
{
	//TODO: add args' description ?
	printf("Usage: %s " USG USG_OPT "\n", exec_name);
}

static int ft_incorrect_args(char *argv_0)
{
	ft_putendl_fd("Error! Incorrect usage!", 2);
	print_usage(ft_trim_execname(argv_0));
	return (1);
}

/**
 * @param argv: philo_amount time_to_die time_to_eat time_to_sleep eat_times
 */
int main (int argc, char *argv[])
{
	t_philo_config config;

	if (!ft_parse_args(argc, &argv[1], &config))
	{
		return ft_incorrect_args(argv[0]);
	}
	return (0);
}
