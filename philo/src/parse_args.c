
#include "philo.h"
/*TODO: Any limits for parameters?*/
static bool	ft_validate_config(t_philo_config *config)
{
	if (config->count < 1)
		return (false);
	if (config->tt_die < 1)
		return (false);
	if (config->tt_eat < 1)
		return (false);
	if (config->tt_sleep < 1)
		return (false);
	return (true);
}

bool	ft_is_all_digits(char **argv)
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
			if (!ft_isdigit(c))
			{
				return (false);
			}
			c = argv[i][++j];
		}
	}
	return (true);
}

void	ft_parse_config(char **argv, t_philo_config *config)
{
	int i;

	i = -1;
	while (argv[++i])
	{
		if (i == 0)
			config->count = ft_atoi(argv[i]);
		else if (i == 1)
			config->tt_die = ft_atoi(argv[i]);
		else if (i == 2)
			config->tt_eat = ft_atoi(argv[i]);
		else if (i == 3)
			config->tt_sleep = ft_atoi(argv[i]);
		else if (i == 4)
			config->eat_times = ft_atoi(argv[i]);
	}
}

bool	ft_parse_args(int argc, char **argv, t_philo_config *config)
{
	if ((argc != 5 && argc != 6) || (!ft_is_all_digits(&argv[1])))
		return (false);
	else
		ft_parse_config(&argv[1], config);
	return (ft_validate_config(config));
}
