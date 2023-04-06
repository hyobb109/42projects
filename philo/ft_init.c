/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:41:01 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/06 21:51:58 by hyobicho         ###   ########.fr       */
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
		{
			free(info->forks);
			return (0);
		}
	}
	if (pthread_mutex_init(&info->print, NULL) || pthread_mutex_init(&info->state, NULL))
	{
		free(info->forks);
		return (0);
	}
	return (1);
}

int	init_info(t_info *info)
{
	info->philos = (t_philo *)malloc(sizeof(t_philo) * info->av[PHILOSOPHERS]);
	if (info->philos == NULL)
		return (ft_error("Error: malloc failed\n"));
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->av[PHILOSOPHERS]);
	if (info->forks == NULL)
		return (free_philo(info->philos, "Error: fork malloc failed\n"));
	gettimeofday(&info->start_time, NULL);
	if (!init_mutexes(info))
		return (free_philo(info->philos, "Error: mutex init failed\n"));
	return (0);
}