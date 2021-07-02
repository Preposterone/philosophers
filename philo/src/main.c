
#include "philo.h"
#include <pthread.h>

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

void *job () {
    printf("Test for threads\n");
    sleep(3);
    printf("Ending thread\n");

    return NULL;
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

	pthread_t t1 = {0};
	pthread_t t2 = {0};

    if (pthread_create(&t1, NULL, &job, NULL) != 0) {а
        return 1;
    }

    if (pthread_create(&t2, NULL, &job, NULL) != 0) {
        return 2;
    }

    if (pthread_join(t1, NULL) != 0) {
        return 3;
    }
    if (pthread_join(t2, NULL) != 0) {
        return 4;
    }
	return (0);
}
