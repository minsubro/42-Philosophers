/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_action_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:58:17 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/25 20:08:59 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*kill_wait(void *temp)
{
	t_info	*info;
	int		i;

	i = 0;
	info = (t_info *)temp;
	usleep(100);
	sem_wait(info->table);
	usleep(500);
	while (i < info->philo_num)
	{
		i++;
		kill(info->pid[i], 2);
	}
	return (NULL);
}

void	main_action(t_info info)
{
	pthread_t	killer;
	int			i;

	usleep(300);
	sem_post(info.start);
	pthread_create(&killer, 0, kill_wait, &info);
	i = 0;
	while (i < info.philo_num)
	{
		waitpid(info.pid[i], 0, 0);
		i++;
	}
	pthread_detach(killer);
}
