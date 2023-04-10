/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:17 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/10 20:27:58 by hyobicho         ###   ########.fr       */
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

#define C_NRML "\033[0m"
#define C_RED  "\033[31m"
#define C_YLLW "\033[33m"
#define C_GREN "\033[32m"
#define C_BLUE "\033[34m"

typedef enum e_error
{
	INVALID = -1,
	VALID
}	t_error;

typedef enum e_arguments
{
	PHILOSOPHERS,
	DIE,
	EAT,
	SLEEP,
	MUST_EAT,
}	t_arguments;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	FINISHED,
	DEAD
}	t_status;

typedef struct s_philo
{
	pthread_t		tid;
	int				n;
	int				eat;
	int				status;
	struct timeval	eat_start;
	struct s_info	*info;
} t_philo;

typedef struct	s_info
{
	int	ac;
	int	av[5];
	t_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	lock;
	pthread_mutex_t	lock2;
	int		finished;
	int		dead;
	struct timeval	start_time;
} t_info;

int		ft_positive_atoi(const char *str);
int		ft_error(char *message);
int		check_args(int argc, char **argv, t_info *args);
int		free_philo(t_philo *philos, char *message);
int		init_info(t_info *info);
void	*start_routine(void *arg);
void	check_life(t_philo *philo);

#endif