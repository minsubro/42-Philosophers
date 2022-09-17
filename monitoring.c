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
	if (philo->is_die)
	{
		pthread_mutex_lock(info->guard);
		if (get_time() - philo->eat_time >= philo->info->time_to_die)
		{
			printf("%lld %d died\n", elapsed_time(philo->info), philo->num);
			info->is_dead = 0;
		}
	}
	pthread_mutex_unlock(philo->guard);
	pthread_mutex_unlock(info->guard);
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
			if (temp[i].is_die == 0)
				cnt++;
			pthread_mutex_unlock(temp[i].guard);
			i++;
		}
		pthread_mutex_lock(info->guard);
		if (cnt == info->philo_num)
		{
			info->is_dead = 0;
		}
		pthread_mutex_unlock(info->guard);
	}
}