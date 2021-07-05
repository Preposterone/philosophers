
#include "philo.h"

static void print_usage(char *exec_name)
{
	//TODO: add args' description ?
	printf("Usage: %s " USG USG_OPT "\n", exec_name);
}

int ft_incorrect_args(char *argv_0)
{
	ft_putendl_fd("Error! Incorrect usage!", 2);
	print_usage(ft_trim_execname(argv_0));
	return (1);
}

static bool	ft_is_all_digits(char **argv)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		c = argv[i][++j];
		while (c)
		{
			if (!ft_isdigit(c) || j >= 10)
			{
				return (false);
			}
			c = argv[i][++j];
		}
	}
	return (true);
}

static bool	ft_parse_config(char **argv, t_config *config)
{
	int		i;
	int64_t	tmp;

	i = -1;
	while (argv[++i])
	{
		tmp = ft_atoll(argv[i]);
		if (tmp <= 0 || tmp > INT_MAX)
			return (false);
		if (i == 0)
			config->count = (int)tmp;
		else if (i == 1)
			config->tt_die = (int)tmp;
		else if (i == 2)
			config->tt_eat = (int)tmp;
		else if (i == 3)
			config->tt_sleep = (int)tmp;
		else if (i == 4)
			config->eat_times = (int)tmp;
	}
	return (true);
}

bool	ft_parse_args(int argc, char **argv, t_config *config)
{
	if ((argc != 5 && argc != 6) || (!ft_is_all_digits(argv)))
		return (false);
	else if (!ft_parse_config(argv, config))
		return (false);
	return (true);
}
