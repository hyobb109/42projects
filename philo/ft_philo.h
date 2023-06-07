/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:17 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/05 19:28:12 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define C_NRML "\033[0m"
# define C_RED  "\033[31m"
# define C_YLLW "\033[33m"
# define C_GREN "\033[32m"
# define C_BLUE "\033[34m"
# define INVALID -1
# define VALID 0
# define PHILOSOPHERS 0
# define DIE 1
# define EAT 2
# define SLEEP 3
# define MUST_EAT 4
# define EATING 0
# define NOT_EATING 1

typedef struct s_philo
{
	pthread_t		tid;
	int				n;
	int				eat;
	int				status;
	int				thinking_time;
	int				left;
	int				right;
	long long		start;
	long long		last;
	long long		dead_time;
	struct s_info	*info;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	f_lock;
	int				used;
}	t_fork;

typedef struct s_info
{
	int				ac;
	int				av[5];
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	time;
	pthread_mutex_t	eat_count;
	pthread_mutex_t	life;
	pthread_mutex_t	flag;
	int				finished;
	int				dead;
	long long		start;
}	t_info;

int			ft_positive_atoi(const char *str);
int			ft_error(char *message);
int			check_args(int argc, char **argv, t_info *args);
int			free_all(t_info	*info, char *message);
int			init_info(t_info *info);

int			create_threads(t_info *info);
int			join_threads(t_info *info);
int			destroy_mutexes(t_info *info);
void		update_status(pthread_mutex_t *lock, int *status, int val);

void		monitor_threads(t_info *info);
int			finished(t_philo *philo);
int			dead(t_philo *philo);
int			is_eating(t_philo *philo);

void		*start_routine(void *arg);
int			get_forks(t_philo *philo);
void		put_down_forks(t_philo *philo);
void		print_state(t_philo *philo, long long t, char *msg, char *color);

long long	curr_time(void);
int			newsleep(t_philo *philo, long long time);

#endif