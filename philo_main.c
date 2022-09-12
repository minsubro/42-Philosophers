/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsu <minsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:49:47 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/12 22:05:02 by minsu            ###   ########.fr       */
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
 
int philo_init(t_info info, t_philo **philo, pthread_mutex_t *fork)
{
	int		i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * info.philo_num);
	if (!(*philo))
		return (FALSE);
	i = 0;
	while (i < info.philo_num)
	{
		(*philo)[i].num = i;
		(*philo)[i].is_die = 0;
		(*philo)[i].eat_count = 0;
		(*philo)[i].info = info;
		(*philo)[i].eat_time = 0;
		if (i == 0)
			(*philo)[i].left_fork = fork[info.philo_num - 1];
		else
			(*philo)[i].left_fork = fork[i - 1];
		(*philo)[i].right_fork = fork[i];
	}
}

int main(int ac, char **av)
{
	pthread_mutex_t *fork;
	pthread_mutex_t *start;
	t_info	info;
	t_philo	*philo;

	pthread_mutex_init(start);
	pthread_mutex_lock(start);
	if (make_info(&info, ac, av) == FALSE)
	{
		ft_error("invalid argument!!");
		return (0);
	}
	fork = fork_init(info.philo_num);
	if (philo_init(info, philo, fork) == FALSE)
	{
		ft_error("Memory allocation failed!!");
		return (0);
	}
	pthread_mutex_unlock(start);	
}