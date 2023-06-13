/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:51:41 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/13 17:56:30 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	create_threads(t_info *info)
{
	int	i;

	pthread_mutex_lock(&info->flag);
	i = -1;
	while (++i < info->av[PHILOS])
	{
		if (pthread_create(&info->philos[i].tid, NULL,
				start_routine, &info->philos[i]))
		{
			pthread_mutex_unlock(&info->flag);
			return (free_all(info, "Error: pthread_create failed\n"));
		}
	}
	info->start = curr_time();
	i = -1;
	while (++i < info->av[PHILOS])
	{
		info->philos[i].last = info->start;
	}
	pthread_mutex_unlock(&info->flag);
	return (0);
}

int	join_threads(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->av[PHILOS])
	{
		if (pthread_join(info->philos[i].tid, NULL))
			return (free_all(info, "Error: pthread_join failed\n"));
	}
	return (0);
}

int	destroy_mutexes(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->av[PHILOS])
	{
		if (pthread_mutex_destroy(&info->forks[i].f_lock))
		{
			return (free_all(info, "Error: fork mutex destroy failed\n"));
		}
	}
	if (pthread_mutex_destroy(&info->flag))
		return (free_all(info, "Error: flag mutex destroy failed\n"));
	if (pthread_mutex_destroy(&info->print))
		return (free_all(info, "Error: print mutex destroy failed\n"));
	if (pthread_mutex_destroy(&info->time))
		return (free_all(info, "Error: time mutex destroy failed\n"));
	if (pthread_mutex_destroy(&info->eat_count))
		return (free_all(info, "Error: eat_count mutex destroy failed\n"));
	if (pthread_mutex_destroy(&info->life))
		return (free_all(info, "Error: life mutex destroy failed\n"));
	return (0);
}
