/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:08:47 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/25 20:11:14 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		now_time;

	gettimeofday(&time, 0);
	now_time = time.tv_usec / 1000 + time.tv_sec * 1000;
	return (now_time);
}

long long	elapsed_time(long long start_time)
{
	return (get_time() - start_time);
}
