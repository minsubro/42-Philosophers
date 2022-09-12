#include "philo.h"

pthread_mutex_t	*fork_init(int philo_num)
{
	pthread_mutex_t *new;
	int				i;

	new = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_num);
	return (new);
}
