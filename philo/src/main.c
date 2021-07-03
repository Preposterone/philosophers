
#include "philo.h"
#include <pthread.h>
#include "slog.h"

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

int forks;
pthread_mutex_t mutex;

void *job (void *index) {

	pthread_mutex_lock(&mutex);

	if (forks > 0) {
		slogd("Forks: %d", forks);
		forks--;
		printf("Philosopher '%d' has taken a fork!\n", *(int*)index + 1);
	}
	pthread_mutex_unlock(&mutex);

	return NULL;
}

/**
 * @param argv: philo_amount time_to_die time_to_eat time_to_sleep eat_times
 */
int main (int argc, char *argv[])
{
	t_philo_config config;
	slog_init("example", SLOG_FLAGS_ALL, 1);

	pthread_mutex_init(&mutex, NULL);

	if (!ft_parse_args(argc, &argv[1], &config))
	{
		return ft_incorrect_args(argv[0]);
	}

	forks = config.count;
	pthread_t t[config.count];

	for (int philo = 0; philo < config.count; philo++) {
	    int philo_index = philo;
		if (pthread_create(&t[philo], NULL, &job, (void *)&philo_index) != 0) {
			exit (1);
		}
	}

	for (int i = 0; i < config.count; i++){
        if (pthread_join(t[i], NULL) != 0) {
            exit (2);
        }
    }

	pthread_mutex_destroy(&mutex);
	slogd("Num of forks: %d\n", forks);

	slog_destroy();
	return (0);
}
