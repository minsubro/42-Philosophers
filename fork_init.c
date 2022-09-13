/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:04:04 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/13 13:04:05 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*fork_init(int philo_num)
{
	pthread_mutex_t *new;
	int				i;

	i = 0;
	new = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo_num);
	while (i < philo_num)
	{
		pthread_mutex_init(&new[i], 0);
		i++;
	}
	return (new);
}
