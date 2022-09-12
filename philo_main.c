/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsu <minsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:49:47 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/10 21:35:18 by minsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
}

int	make_info(t_info *info, int ac, char **av)
{
	if ((ac != 5 && ac != 6) || av_check(av) == FALSE)
		return (FALSE);
	info->philo_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->philo_must_eat = ft_atoi(av[5]);
	return (TRUE);
}



int philo_init(t_info info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * info.philo_num);
	if (!philo)
		return (FALSE);
}

int main(int ac, char **av)
{
	pthread_mutex_t *fork;
	t_info	info;
	t_philo	*philo;

	if (make_info(&info, ac, av) == FALSE)
	{
		ft_error("invalid argument!!");
		return (0);
	}
	fork = fork_init(info.philo_num);
	if (philo_init(info) == FALSE)
	{
		ft_error("Memory allocation failed!!");
		return (0);
	}
}