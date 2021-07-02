
#include "philo.h"

static bool	ft_validate_config(int argc, t_philo_config *config)
{
	if (config->count < 1 || config->count > INT_MAX)
		return (false);
	if (config->tt_die < 1 || config->tt_die > INT_MAX)
		return (false);
	if (config->tt_eat < 1 || config->tt_eat > INT_MAX)
		return (false);
	if (argc == 6 && (config->tt_sleep < 1 || config->tt_sleep > INT_MAX))
		return (false);
	return (true);
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

static void	ft_parse_config(char **argv, t_philo_config *config)
{
	int i;

	i = -1;
	while (argv[++i])
	{
		if (i == 0)
			config->count = ft_atoll(argv[i]);
		else if (i == 1)
			config->tt_die = ft_atoll(argv[i]);
		else if (i == 2)
			config->tt_eat = ft_atoll(argv[i]);
		else if (i == 3)
			config->tt_sleep = ft_atoll(argv[i]);
		else if (i == 4)
			config->eat_times = ft_atoll(argv[i]);
	}
}

bool	ft_parse_args(int argc, char **argv, t_philo_config *config)
{
	if ((argc != 5 && argc != 6) || (!ft_is_all_digits(argv)))
		return (false);
	else
		ft_parse_config(argv, config);
	return (ft_validate_config(argc, config));
}
