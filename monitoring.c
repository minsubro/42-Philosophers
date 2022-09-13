/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:03:59 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/13 20:35:40 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_died(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(philo->guard);
	if (get_time() - philo->eat_time >= philo->info->time_to_die)
	{
		printf("%lld %d died\n", elapsed_time(philo->info), philo->num + 1);
		info->is_dead = 0;
	}
	pthread_mutex_unlock(philo->guard);
}

int	must_eat(t_philo *philo)
{
	if (philo->eat_count == philo->info->philo_must_eat)
	{
		philo->is_die = 0;
		return (1);
	}
	else
		return (0);
}

void ft_monitoring(t_info *info, t_philo **philo)
{
	int		i;
	int		cnt;
	t_philo	*temp;

	temp = *philo;
	while (info->is_dead)
	{
		i = 0;
		cnt = 0;
		while (i < info->philo_num && info->is_dead)
		{
			is_died(&temp[i], info);
			pthread_mutex_lock(temp[i].guard);
			if (must_eat(&temp[i]))
				cnt++;
			pthread_mutex_unlock(temp[i].guard);
			i++;
		}
		if (cnt == info->philo_num)
		{
			pthread_mutex_lock(info->guard);
			info->is_dead = 0;
			pthread_mutex_unlock(info->guard);
		}
	}
}