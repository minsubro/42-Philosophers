/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:51:49 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/25 20:09:30 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	eat_time_check(long long last_eat_time, t_info info)
{
	if (get_time() - last_eat_time >= info.time_to_eat)
		return (0);
	else
		return (1);
}

void	eatting(t_info info, t_philo *philo)
{
	sem_wait(philo->check_sem);
	philo->last_eat_time = get_time();
	sem_post(philo->check_sem);
	sem_wait(info.print);
	printf("%lld %d is eating\n", elapsed_time(info.start_time), philo->num + 1);
	sem_post(info.print);
	while (eat_time_check(philo->last_eat_time, info))
		usleep(100);
}

int	sleep_time_check(long long sleep_start, t_info info)
{
	if (get_time() - sleep_start >= info.time_to_sleep)
		return (0);
	else
		return (1);
}

void	sleeping(t_info info, t_philo *philo)
{
	long long	sleep_start;

	sleep_start = get_time();
	sem_wait(info.print);
	printf("%lld %d is sleeping\n", \
		elapsed_time(info.start_time), philo->num + 1);
	sem_post(info.print);
	while (sleep_time_check(sleep_start, info))
		usleep(100);
}

void	thinking(t_info info, t_philo *philo)
{
	sem_wait(info.print);
	printf("%lld %d is thinking\n", \
		elapsed_time(info.start_time), philo->num + 1);
	sem_post(info.print);
}
