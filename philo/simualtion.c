/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simualtion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:57:22 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/24 17:31:37 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simualtion_start(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	info->start_time = get_time();
	while (i < info->philo_num)
	{
		(*philo)[i].eat_time = get_time();
		pthread_create(&((*philo)[i].simulation), \
			NULL, simulation, &((*philo)[i]));
		i++;
	}
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
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	if (philo->num % 2 == 0)
		usleep(800);
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
		if (dead_check(philo))
			printf("%lld %d is thinking\n", \
				elapsed_time(philo->info), philo->num);
	}
	return (NULL);
}
