/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:51:00 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/06 17:29:40 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE -1

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_info
{
	int philo_num;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int philo_must_eat;
}		t_info;


#endif