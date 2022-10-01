/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:04:13 by minsukan          #+#    #+#             */
/*   Updated: 2022/10/01 13:25:05 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		ref = ref * 10 + (str[i] - '0');
		if (ref > INT_MAX || ref < INT_MIN || !(str[i] >= '0' && str[i] <= '9'))
			return (FALSE);
		i++;
	}
	if (i == 0)
		return (FALSE);
	return (ref);
}

int	av_check(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
