/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:27:10 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/12 19:57:07 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	check_eating_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->time);
	philo->last = curr_time();
	pthread_mutex_unlock(&philo->info->time);
	// update_status(&philo->info->flag, &philo->status, EATING);
	print_state(philo, philo->last, "is eating", GREN);
}

int	get_forks(t_philo *philo)
{
	while (!philo->f_first || !philo->f_second)
	{
		if (dead(philo) || finished(philo))
			return (0);
		pthread_mutex_lock(&philo->first->f_lock);
		if (!philo->first->used)
		{
			philo->first->used = 1;
			philo->f_first = 1;
			print_state(philo, curr_time(), "has taken a fork", NRML);
		}
		pthread_mutex_unlock(&philo->first->f_lock);
		if (dead(philo) || finished(philo))
			return (0);
		pthread_mutex_lock(&philo->second->f_lock);
		if (!philo->second->used)
		{
			philo->second->used = 1;
			philo->f_second = 1;
			print_state(philo, curr_time(), "has taken a fork", NRML);
		}
		pthread_mutex_unlock(&philo->second->f_lock);
	}
	check_eating_time(philo);
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
