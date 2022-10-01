/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:57:03 by minsukan          #+#    #+#             */
/*   Updated: 2022/10/01 13:28:02 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	make_process(t_info info)
{
	int	i;

	i = 0;
	while (1)
	{
		info.pid[i] = fork();
		if (info.pid[i] == 0)
			break ;
		if (i == info.philo_num - 1)
			break ;
		i++;
	}
	return (i);
}

void	make_philo(t_info info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	info.start_time = get_time();
	philo->num = make_process(info);
	philo->eat_count = 0;
	if (info.pid[philo->num] == 0)
	{
		sem_wait(info.table);
		philo->philo_name = ft_strjoin("philo", ft_itoa(philo->num));
		sem_unlink(philo->philo_name);
		philo->check_sem = sem_open(philo->philo_name, O_CREAT, 0644, 1);
		info.philo = philo;
		philo_action(info, philo);
		end_routine(philo);
	}
	free(philo);
}
