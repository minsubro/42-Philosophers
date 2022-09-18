/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:55:21 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/18 12:10:37 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_info *info, t_philo **philo, pthread_mutex_t *fork)
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
