/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:51:00 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/13 20:16:22 by minsukan         ###   ########.fr       */
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
	long long		start_time;
	int				philo_num;
	int 			time_to_die;
	int 			time_to_eat;
	int 			time_to_sleep;
	int 			philo_must_eat;
	int				is_dead;
	pthread_mutex_t *guard;
}					t_info;

typedef struct s_philo
{
	int				num;
	long long		eat_time;
	int				eat_count;
	int				is_die;
	t_info			*info;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *guard;
	pthread_t		simulation;
}					t_philo;


int	ft_atoi(char *str);
int	av_check(char **av);
pthread_mutex_t	*fork_init(int philo_num);
void ft_monitoring(t_info *info, t_philo **philo);
void	is_died(t_philo *philo, t_info *info);
long long get_time(void);
long long elapsed_time(t_info *info);

#endif