/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:17 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/01 16:40:27 by hyobicho         ###   ########.fr       */
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
	MUST_EAT
}	t_arguments;

typedef struct s_philo
{
	int		n;
	int		eat;
	pthread_t	tid;
	struct timeval	finish_eating;
	struct s_info	*info;
} t_philo;

typedef struct	s_info
{
	int	ac;
	int	av[5];
	t_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	struct timeval	start_time;
} t_info;

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_positive_atoi(const char *str);
int		ft_error(char *message);

#endif