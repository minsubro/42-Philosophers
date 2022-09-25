/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:59:49 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/25 20:10:18 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef struct s_philo
{
	long long	last_eat_time;
	char		*philo_name;
	int			eat_count;
	int			num;
	pthread_t	die_check;
	sem_t		*check_sem;
}				t_philo;

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
	t_philo		*philo;
}				t_info;

void		ft_error(char *str);
int			ft_atoi(char *str);
long long	get_time(void);
long long	elapsed_time(long long start_time);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_itoa(int n);
void		*die_check(void *temp);
void		eatting(t_info info, t_philo *philo);
void		sleeping(t_info info, t_philo *philo);
void		thinking(t_info info, t_philo *philo);
void		start_routine(t_info info);
void		end_routine(t_philo *philo);
t_info		create_info(int ac, char **av);
void		make_philo(t_info info);
void		main_action(t_info info);
void		philo_action(t_info info, t_philo *philo);

#endif