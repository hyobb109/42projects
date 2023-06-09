/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:41:01 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/09 21:30:39 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	init_mutexes(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->av[PHILOSOPHERS])
	{
		if (pthread_mutex_init(&info->forks[i].f_lock, NULL))
			return (0);
		info->forks[i].used = 0;
	}
	if (pthread_mutex_init(&info->flag, NULL)
		|| pthread_mutex_init(&info->print, NULL)
		|| pthread_mutex_init(&info->time, NULL)
		|| pthread_mutex_init(&info->eat_count, NULL)
		|| pthread_mutex_init(&info->life, NULL))
		return (0);
	return (1);
}

static void	init_forks(t_info *info, int num)
{
	if (num % 2)
	{
		info->philos[num - 1].first = &info->forks[num - 1];
		info->philos[num - 1].second = &info->forks[num
			% info->av[PHILOSOPHERS]];
	}
	else
	{
		info->philos[num - 1].second = &info->forks[num
			% info->av[PHILOSOPHERS]];
		info->philos[num - 1].first = &info->forks[num - 1];
	}
}

static void	init_philos(t_info *info)
{
	int			i;
	long long	idle_time;

	i = -1;
	idle_time = info->av[DIE] - info->av[EAT] - info->av[SLEEP];
	while (++i < info->av[PHILOSOPHERS])
	{
		info->philos[i].n = i + 1;
		info->philos[i].eat = 0;
		info->philos[i].status = NOT_EATING;
		info->philos[i].thinking_time = idle_time / 2;
		info->philos[i].forks_cnt = 0;
		info->philos[i].info = info;
		// info->philos[i].last = info->start;
		info->philos[i].dead_time = 0;
		init_forks(info, i + 1);
	}
}

int	init_info(t_info *info)
{
	info->philos = malloc(sizeof(t_philo) * info->av[PHILOSOPHERS]);
	if (info->philos == NULL)
		return (ft_error("Error: malloc failed\n"));
	info->forks = malloc(sizeof(t_fork) * info->av[PHILOSOPHERS]);
	if (info->forks == NULL)
	{
		free(info->philos);
		return (ft_error("Error: fork malloc failed\n"));
	}
	info->start = curr_time();
	init_philos(info);
	if (!init_mutexes(info))
		return (free_all(info, "Error: mutex init failed\n"));
	info->finished = 0;
	info->dead = 0;
	return (0);
}
