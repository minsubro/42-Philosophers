/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:22:28 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/24 10:27:29 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int ft_atoi(char *str)
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
			ft_error("invalid argument!!");
		str++;
	}
	while (str[i])
	{
		if (ref > INT_MAX || ref < INT_MIN || !(str[i] >= '0' && str[i] <= '9'))
			ft_error("invalid argument!!");
		ref = ref * 10 + (str[i] - '0');
		i++;
	}
	if (i == 0)
		ft_error("invalid argument!!");
	return (ref);
}