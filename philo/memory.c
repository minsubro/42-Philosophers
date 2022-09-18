/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:56:41 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/18 11:57:09 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	memory_free(t_philo *philo, t_info info, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < info.philo_num)
	{
		pthread_join(philo[i].simulation, 0);
		pthread_mutex_destroy(philo[i].guard);
		free(philo[i].guard);
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
	pthread_mutex_destroy(info.guard);
	free(philo);
	free(fork);
}
