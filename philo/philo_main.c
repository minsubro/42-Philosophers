/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:49:47 by minsukan          #+#    #+#             */
/*   Updated: 2022/10/01 13:22:21 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
}

void	exception_case(long long time)
{
	printf("%d %d has taken a fork\n", 0, 1);
	usleep(time * 1000);
	printf("%lld %d died\n", time, 1);
}

int	make_info(t_info *info, int ac, char **av)
{
	if ((ac != 5 && ac != 6) || av_check(av) == FALSE)
		return (FALSE);
	info->philo_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->is_dead = 1;
	if (ac == 6)
		info->philo_must_eat = ft_atoi(av[5]);
	else
		info->philo_must_eat = -1;
	info->guard = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!(info->guard))
		return (FALSE);
	pthread_mutex_init(info->guard, 0);
	if (info->philo_num == 1)
		exception_case(info->time_to_die);
	return (TRUE);
}

int	main(int ac, char **av)
{
	pthread_mutex_t	*fork;
	t_info			info;
	t_philo			*philo;

	if (make_info(&info, ac, av) == FALSE)
	{
		ft_error("invalid argument!!");
		return (0);
	}
	if (info.philo_num <= 1)
		return (0);
	fork = fork_init(info.philo_num);
	philo = (t_philo *)malloc(sizeof(t_philo) * info.philo_num);
	if (philo_init(&info, &philo, fork) == FALSE)
	{
		ft_error("Memory allocation failed!!");
		return (0);
	}
	simualtion_start(&philo, &info);
	ft_monitoring(&info, &philo);
	memory_free(philo, info, fork);
}
