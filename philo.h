/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsu <minsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:51:00 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/10 21:34:21 by minsu            ###   ########.fr       */
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

typedef struct s_philo
{
	long long		eat_time;
	long long		sleep_time;
	int				eat_count;
	int				status;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	pthread_t		simulation;
}					t_philo;

int	ft_atoi(char *str);
int	av_check(char **av);
int philo_init(t_info info);

#endif