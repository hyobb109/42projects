/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:23:51 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/13 18:20:59 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	dead_time(t_philo *philo)
{
	int			flag;
	long long	curr;

	flag = 0;
	pthread_mutex_lock(&philo->info->time);
	curr = curr_time();
	if (curr - philo->last >= philo->info->av[DIE])
	{
		philo->dead_time = curr - philo->info->start;
		flag = 1;
	}
	pthread_mutex_unlock(&philo->info->time);
	return (flag);
}

static void	check_life(t_philo *philo)
{
	if (dead_time(philo))
	{
		pthread_mutex_lock(&philo->info->print);
		printf("%s%lld %d %s\n", RED, philo->dead_time, philo->n, "died");
		pthread_mutex_lock(&philo->info->life);
		philo->info->dead = 1;
		pthread_mutex_unlock(&philo->info->life);
		pthread_mutex_unlock(&philo->info->print);
	}
}

void	monitor_threads(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		check_life(&info->philos[i]);
		if (dead(&info->philos[i]) || finished(&info->philos[i]))
			break ;
		i = (i + 1) % info->av[PHILOS];
		usleep(500);
	}
}
