/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:59:45 by minsukan          #+#    #+#             */
/*   Updated: 2022/10/01 13:32:28 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error(char *str)
{
	printf("%s", str);
	exit(1);
}

void	take_fork(t_info info, t_philo *philo)
{
	sem_wait(info.fork);
	sem_wait(info.print);
	printf("%lld %d has taken a fork\n", \
		elapsed_time(info.start_time), philo->num + 1);
	sem_post(info.print);
	sem_wait(info.fork);
	sem_wait(info.print);
	printf("%lld %d has taken a fork\n", \
		elapsed_time(info.start_time), philo->num + 1);
	sem_post(info.print);
}

void	put_fork(t_info info)
{
	sem_post(info.fork);
	sem_post(info.fork);
}

void	philo_action(t_info info, t_philo *philo)
{
	start_routine(info);
	philo->last_eat_time = info.start_time;
	pthread_create(&philo->die_check, 0, die_check, &info);
	if (philo->num % 2 == 0)
		usleep(100);
	while (1)
	{
		take_fork(info, philo);
		eatting(info, philo);
		(philo->eat_count)++;
		put_fork(info);
		if (info.philo_must_eat == philo->eat_count)
			break ;
		sleeping(info, philo);
		thinking(info, philo);
	}
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	philo;

	if (ac != 5 && ac != 6)
		ft_error("invalid argument!!");
	info = create_info(ac, av);
	info.philo = &philo;
	sem_wait(info.start);
	make_philo(info);
	main_action(info);
}
