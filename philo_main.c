/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:49:47 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/06 17:33:54 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
}

int	ft_atoi(char *str)
{
	long long	ref;
	int			i;

	i = 0;
	ref = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (FALSE);
		str++;
	}
	while (str[i])
	{
		if (ref > INT_MAX || ref < INT_MIN)
			return (FALSE);
		ref = ref * 10 + (str[i] - '0');
		i++;
	}
	if (i == 0)
		return (FALSE);
	return (ref);
}

int	av_check(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	make_info(t_info *info, int ac, char **av)
{
	if (ac != 5 || ac != 6 || av_check(av) == FALSE)
	{
		ft_error("invalid number of arguments!!");
		return (FALSE);
	}
	info->philo_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->philo_must_eat = ft_atoi(av[5]);
	return (TRUE);
}

int main(int ac, char **av)
{
	t_info	info;

	
	if (make_info(&info, ac, av) == FALSE)
	{
		ft_error("invalid argument!!");
		return (0);
	}
}