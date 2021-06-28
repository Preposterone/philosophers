
#include "philo.h"

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
	bool ret;

	ret = true;
	if ((argc != 5 && argc != 6) || (!ft_is_all_digits(argv)))
	{
		ret = false;
	}
	else
	{
		ft_parse_config(argv, config);
	}
	return (ret);
}
