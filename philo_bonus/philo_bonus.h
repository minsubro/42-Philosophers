/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:59:49 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/24 15:32:29 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef struct s_info
{
	long long	start_time;
	pid_t		*pid;
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			philo_must_eat;
	int			all_eat;
	sem_t		*table;
	sem_t		*fork;
	sem_t		*start;
	sem_t		*print;
}				t_info;

typedef	struct s_philo
{
	long long	last_eat_time;
	int			eat_count;
	int			num;
}				t_philo;


void		ft_error(char *str);
int			ft_atoi(char *str);
long long	get_time(void);
long long	elapsed_time(t_info info);


#endif