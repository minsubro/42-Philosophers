/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:49:47 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/13 20:27:18 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
}

int	make_info(t_info *info, int ac, char **av)
{
	if ((ac != 5 && ac != 6) || av_check(av) == FALSE)
		return (FALSE);
	info->philo_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->is_dead = 1;
	if (ac == 6)
		info->philo_must_eat = ft_atoi(av[5]);
	else
		info->philo_must_eat = -1;
	info->guard = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!(info->guard))
		return (FALSE);
	pthread_mutex_init(info->guard, 0);
	return (TRUE);
}
 
int philo_init(t_info *info, t_philo **philo, pthread_mutex_t *fork)
{
	int		i;

	i = 0;
	while (i < info->philo_num)
	{
		(*philo)[i].num = i + 1;
		(*philo)[i].is_die = 1;
		(*philo)[i].eat_count = 0;
		(*philo)[i].info = info;
		if (i == 0)
			(*philo)[i].left_fork = &fork[info->philo_num - 1];
		else
			(*philo)[i].left_fork = &fork[i - 1];
		(*philo)[i].right_fork = &fork[i];
		(*philo)[i].guard = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!((*philo)[i].guard))
			return (FALSE);
		pthread_mutex_init((*philo)[i].guard, 0);
		i++;
	}
	return (TRUE);
}

long long get_time()
{
	struct timeval time;
	long long now_time;
	
	gettimeofday(&time, 0);
	now_time = time.tv_usec / 1000 + time.tv_sec * 1000;
	return (now_time);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->info->guard);
	if (philo->info->is_dead)
	{
		printf("%lld %d has taken a fork\n", get_time() - philo->info->start_time, philo->num);
	}
	pthread_mutex_unlock(philo->info->guard);
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->info->guard);
	if (philo->info->is_dead)
		printf("%lld %d has taken a fork\n", get_time() - philo->info->start_time, philo->num);
	pthread_mutex_unlock(philo->info->guard);
}

int eat_time_check(long long starttime, t_philo *philo)
{
	if (get_time() - starttime >= philo->info->time_to_eat)
	{
		return (0);
	}
	else
		return (1);
}

void	eatting(t_philo *philo)
{
	long long start_time;
	
	pthread_mutex_lock(philo->info->guard);
	philo->eat_time = get_time();
	printf("%lld %d is eating\n", elapsed_time(philo->info), philo->num);
	pthread_mutex_unlock(philo->info->guard);
	while (eat_time_check(philo->eat_time, philo))
		usleep(100);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	sleep_time_check(long long start, t_philo *philo)
{
	if (get_time() - start >= philo->info->time_to_sleep)
		return (0);
	else
		return (1);
}

void sleeping(t_philo *philo)
{
	long long sleep_start;

	if (dead_check(philo))
	{
		sleep_start = get_time();
		printf("%lld %d is sleeping\n", elapsed_time(philo->info), philo->num);
		while (sleep_time_check(sleep_start, philo))
			usleep(100);
	}
	else
		return ;
}

long long elapsed_time(t_info *info)
{
	return (get_time() - info->start_time);
}

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(philo->info->guard);
	if (philo->info->is_dead == 0)
	{
		pthread_mutex_unlock(philo->info->guard);
		return (0);
	}
	pthread_mutex_unlock(philo->info->guard);
	return (1);
}

void	*simulation(void *philo_data)
{
	t_philo *philo;
	
	philo = (t_philo *)philo_data;
	if (philo->num % 2 == 0)
		usleep(100);
	while (dead_check(philo))
	{
		take_left_fork(philo);
		take_right_fork(philo);
		eatting(philo);
		put_fork(philo);
		(philo->eat_count)++;
		if (philo->eat_count == philo->info->philo_must_eat)
		{
			pthread_mutex_lock(philo->guard);
			philo->is_die = 0;
			pthread_mutex_unlock(philo->guard);
			break ;
		}
		sleeping(philo);
		pthread_mutex_lock(philo->info->guard);
		if (philo->info->is_dead)
			printf("%lld %d is thinking\n", elapsed_time(philo->info), philo->num);
		pthread_mutex_unlock(philo->info->guard);
	}
	return (NULL);
}

void simualtion_start(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	info->start_time = get_time();
	while (i < info->philo_num)
	{
		(*philo)[i].eat_time = get_time();
		pthread_create(&((*philo)[i].simulation), NULL, simulation, &((*philo)[i]));
		i++;
	}
}

void thread_join(t_philo *philo, t_info info, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(info.guard);
	while (i < info.philo_num)
	{
		pthread_detach(philo[i].simulation);
		pthread_mutex_destroy(philo[i].guard);
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	pthread_mutex_t *fork;
	t_info			info;
	t_philo			*philo;

	if (make_info(&info, ac, av) == FALSE)
	{
		ft_error("invalid argument!!");
		return (0);
	}
	fork = fork_init(info.philo_num);
	philo = (t_philo *)malloc(sizeof(t_philo) * info.philo_num);
	if (philo_init(&info, &philo, fork) == FALSE)
	{
		ft_error("Memory allocation failed!!");
		return (0);
	}
	simualtion_start(&philo, &info);
	ft_monitoring(&info, &philo);
	thread_join(philo, info, fork);
}