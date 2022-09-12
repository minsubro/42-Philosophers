#include "philo.h"

pthread_mutex_t	*fork_init(int philo_num)
{
	pthread_mutex_t *new;
	int				i;

	new = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_num);
	while (i < philo_num)
	{
		pthread_mutex_init(&new[i], 0);
		i++;
	}
	return (new);
}
