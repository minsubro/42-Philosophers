/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:50:47 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/25 20:07:36 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_unlink(void)
{
	sem_unlink("table");
	sem_unlink("fork");
	sem_unlink("start");
	sem_unlink("print");
}

t_info	create_info(int ac, char **av)
{
	t_info	info;

	info.start_time = 0;
	info.philo_num = ft_atoi(av[1]);
	info.time_to_die = ft_atoi(av[2]);
	info.time_to_eat = ft_atoi(av[3]);
	info.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info.philo_must_eat = ft_atoi(av[5]);
	else
		info.philo_must_eat = -1;
	ft_unlink();
	info.table = sem_open("table", O_CREAT, 0644, info.philo_num);
	info.fork = sem_open("fork", O_CREAT, 0644, info.philo_num);
	info.start = sem_open("start", O_CREAT, 0644, 1);
	info.print = sem_open("print", O_CREAT, 0644, 1);
	info.pid = (pid_t *)malloc(sizeof(pid_t) * info.philo_num);
	return (info);
}
