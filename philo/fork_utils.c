/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:27:10 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/14 15:27:03 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	pickup(t_philo *philo, int order)
{
	if (order == 1)
	{
		philo->first->used = 1;
		philo->f_first = 1;
		print_state(philo, "has taken a fork", NRML);
	}
	else if (order == 2)
	{
		philo->second->used = 1;
		philo->f_second = 1;
		print_state(philo, "has taken a fork", NRML);
	}
	return (1);
}

int	get_forks(t_philo *philo)
{
	while (!philo->f_first)
	{
		pthread_mutex_lock(&philo->first->f_lock);
		if (!philo->first->used)
			pickup(philo, 1);
		pthread_mutex_unlock(&philo->first->f_lock);
		if (!philo->f_first)
			usleep(philo->info->av[PHILOS] * 2);
		if (dead(philo) || finished(philo))
			return (0);
	}
	while (!philo->f_second)
	{
		pthread_mutex_lock(&philo->second->f_lock);
		if (!philo->second->used)
			pickup(philo, 2);
		pthread_mutex_unlock(&philo->second->f_lock);
		if (!philo->f_second)
			usleep(philo->info->av[PHILOS] * 2);
		if (dead(philo) || finished(philo))
			return (0);
	}
	return (1);
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->second->f_lock);
	philo->second->used = 0;
	philo->f_second = 0;
	pthread_mutex_unlock(&philo->second->f_lock);
	pthread_mutex_lock(&philo->first->f_lock);
	philo->first->used = 0;
	philo->f_first = 0;
	pthread_mutex_unlock(&philo->first->f_lock);
}
