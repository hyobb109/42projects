/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:17 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/30 20:13:25 by hyobicho         ###   ########.fr       */
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

typedef struct	s_args
{
	int	ac;
	int	av[5];
} t_args;

typedef struct s_philo
{
	int		n;
	t_args	args;
	pthread_t	tid;
	struct timeval	start_time;
	struct timeval	end_time;
} t_philo;

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_positive_atoi(const char *str);
int		ft_error(char *message);

#endif