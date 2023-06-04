/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:41:01 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/01 22:58:56 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	init_mutexes(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->av[PHILOSOPHERS])
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (0);
	}
	if (pthread_mutex_init(&info->flag, NULL) 
		|| pthread_mutex_init(&info->print, NULL) 
		|| pthread_mutex_init(&info->time, NULL) 
		|| pthread_mutex_init(&info->eat_count, NULL) 
		|| pthread_mutex_init(&info->life, NULL))
		return (0);
	return (1);
}

void	init_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->av[PHILOSOPHERS])
	{
		info->philos[i].n = i + 1;
		info->philos[i].eat = 0;
		info->philos[i].last_eat = info->start_time;
		info->philos[i].status = NOT_EATING;
		info->philos[i].thinking_time = (info->av[DIE] - info->av[EAT] - info->av[SLEEP]) / 2;
		info->philos[i].info = info;
		// time
		info->philos[i].start = info->start; //curr_time?
		info->philos[i].last = info->start;
	}
}

int	init_info(t_info *info)
{
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->av[PHILOSOPHERS]);
	if (info->philos == NULL)
		return (ft_error("Error: malloc failed\n"));
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->av[PHILOSOPHERS]);
	if (info->forks == NULL)
	{
		free(info->philos);
		return (ft_error("Error: fork malloc failed\n"));
	}
	gettimeofday(&info->start_time, NULL);
	// time
	info->start = curr_time();
	init_philos(info);
	if (!init_mutexes(info))
		return (free_all(info, "Error: mutex init failed\n"));
	info->finished = 0;
	info->dead = 0;
	return (0);
}
