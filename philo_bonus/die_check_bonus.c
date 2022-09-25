/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:01:00 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/25 20:08:34 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_die(t_info *info)
{
	sem_wait(info->philo->check_sem);
	if (get_time() - info->philo->last_eat_time >= info->time_to_die)
	{
		sem_post(info->philo->check_sem);
		sem_wait(info->print);
		printf("%lld %d died\n", elapsed_time(info->start_time), \
			info->philo->num + 1);
		sem_post(info->table);
		return (1);
	}
	sem_post(info->philo->check_sem);
	return (0);
}

void	*die_check(void *temp)
{
	t_info	*info;

	info = (t_info *)temp;
	while (1)
	{
		if (is_die(info))
			break ;
		sem_wait(info->philo->check_sem);
		if (info->philo->eat_count == info->philo_must_eat)
			break ;
		sem_post(info->philo->check_sem);
	}
	return (NULL);
}
