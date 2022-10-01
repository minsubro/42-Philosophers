/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:54:08 by minsukan          #+#    #+#             */
/*   Updated: 2022/10/01 13:28:23 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_routine(t_info info)
{
	sem_wait(info.start);
	sem_post(info.start);
}

void	end_routine(t_philo *philo)
{
	pthread_detach(philo->die_check);
	sem_close(philo->check_sem);
	sem_unlink(philo->philo_name);
	exit(0);
}
