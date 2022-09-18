/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:59:11 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/18 12:10:17 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (dead_check(philo))
	{
		printf("%lld %d has taken a fork\n", \
			get_time() - philo->info->start_time, philo->num);
	}
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (dead_check(philo))
		printf("%lld %d has taken a fork\n", \
			get_time() - philo->info->start_time, philo->num);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
