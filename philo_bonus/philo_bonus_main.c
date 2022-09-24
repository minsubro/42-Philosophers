/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:59:45 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/24 18:05:51 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo_bonus.h"

void	ft_error(char *str)
{
	printf("%s", str);
	exit(1);
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
	info.table = sem_open("/table", O_CREAT | O_EXCL, S_IRWXO, info.philo_num);
	info.fork = sem_open("/fork", O_CREAT | O_EXCL, S_IRWXO, info.philo_num);
	info.start = sem_open("/start", O_CREAT | O_EXCL, S_IRWXO, 1);
	info.print = sem_open("/print", O_CREAT | O_EXCL, S_IRWXO, 1);
	info.pid = (pid_t *)malloc(sizeof(pid_t) * info.philo_num);
	return (info);
}

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
	sem_wait(info.start);
	return (i);
}

void	start_routine(t_info info)
{
	sem_wait(info.start);
	sem_post(info.start);
	sem_wait(info.table);
}

void	take_fork(t_info info, t_philo philo)
{
	sem_wait(info.fork);
	sem_wait(info.fork);
	sem_wait(info.print);
	printf("%lld %d has taken a fork\n", elapsed_time(info), philo.num);
	printf("%lld %d has taken a fork\n", elapsed_time(info), philo.num);
	sem_post(info.print);
}

void	philo_action(t_info info, t_philo philo)
{
	start_routine(info);
	philo.last_eat_time = get_time();
	if (philo.num % 2 == 0)
		usleep(100);
	while (1)
	{
		take_fork(info, philo);
		
	}
	
}

void	main_action(t_info info)
{
	info.start_time = get_time();
	//sem_post(info.start);
	while (1)
	{
		printf("check\n");
	}
	
}

int main(int ac, char **av)
{
	t_info	info;
	t_philo	philo;
	
	if (ac != 5 && ac != 6)
		ft_error("invalid argument!!");
	info = create_info(ac, av);
	philo.num = make_process(info);
	if (info.pid[philo.num] == 0)
		philo_action(info, philo);
	else
		main_action(info);
}