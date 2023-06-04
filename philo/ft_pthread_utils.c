/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:51:41 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/02 20:50:07 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	create_threads(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->av[PHILOSOPHERS])
	{
		if (pthread_create(&info->philos[i].tid, NULL, start_routine, &info->philos[i]))
			return (free_all(info, "Error: pthread_create failed\n"));
	}
	return (0);
}

// int	detach_threads(t_info *info)
// {
// 	int	i;

// 	i = -1;
// 	while(++i < info->av[PHILOSOPHERS])
// 	{
// 		if (pthread_detach(info->philos[i].tid))
// 			return (free_all(info, "Error: pthread_detach failed\n"));
// 		// printf("thread %d detached\n", i + 1);
// 	}
// 	return (0);
// }

int	join_threads(t_info *info)
{
	int	i;

	i = -1;
	while(++i < info->av[PHILOSOPHERS])
	{
		if (pthread_join(info->philos[i].tid, NULL))
			return (free_all(info, "Error: pthread_join failed\n"));
		// printf("thread %d joined\n", i + 1);
	}
	return (0);
}

int	destroy_mutexes(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->av[PHILOSOPHERS])
	{
		// pthread_mutex_unlock(&info->forks[i]);
		if (pthread_mutex_destroy(&info->forks[i]))
		{
			printf("forks[%d]\n", i);
			return (free_all(info, "Error: fork mutex destroy failed\n"));
		}
	}
	if (pthread_mutex_destroy(&info->flag))
		return (free_all(info, "Error: flag mutex destroy failed\n"));
		// pthread_mutex_unlock(&info->flag);
	if (pthread_mutex_destroy(&info->print))
		return (free_all(info, "Error: print mutex destroy failed\n"));
		// pthread_mutex_unlock(&info->print);
	if (pthread_mutex_destroy(&info->time))
		return (free_all(info, "Error: time mutex destroy failed\n"));
		// pthread_mutex_unlock(&info->time);
	if (pthread_mutex_destroy(&info->eat_count))
		return (free_all(info, "Error: eat_count mutex destroy failed\n"));
		// pthread_mutex_unlock(&info->eat_count);
	if (pthread_mutex_destroy(&info->life))
		return (free_all(info, "Error: life mutex destroy failed\n"));
		// pthread_mutex_unlock(&info->life);
	return (0);
}
