/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:01:02 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/18 12:07:43 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_time_check(long long starttime, t_philo *philo)
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
	pthread_mutex_lock(philo->guard);
	philo->eat_time = get_time();
	pthread_mutex_unlock(philo->guard);
	if (dead_check(philo))
	{
		printf("%lld %d is eating\n", elapsed_time(philo->info), philo->num);
		while (eat_time_check(philo->eat_time, philo))
			usleep(100);
	}
}

int	sleep_time_check(long long start, t_philo *philo)
{
	if (get_time() - start >= philo->info->time_to_sleep)
		return (0);
	else
		return (1);
}

void	sleeping(t_philo *philo)
{
	long long	sleep_start;

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
