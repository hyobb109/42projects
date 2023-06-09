/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:27:10 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/09 19:35:44 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

// static int	pickup(t_philo *philo, t_fork *first, t_fork *second)
// {
// 	pthread_mutex_lock(&first->f_lock);
// 	if (!first->used)
// 	{
// 		first->used = 1;
// 		printf("%s%lld %d %s\n", NRML, curr_time() - philo->info->start,
// 			philo->n, "has taken a fork");
// 	}
// 	pthread_mutex_unlock(&first->f_lock);
// 	if (philo->info->av[PHILOSOPHERS] == 1 || dead(philo) || finished(philo))
// 	{
// 		return (0);
// 	}
// 	pthread_mutex_lock(&second->f_lock);
// 	if (!second->used)
// 	{
// 		second->used = 1;
// 		printf("%s%lld %d %s\n", NRML, curr_time() - philo->info->start,
// 			philo->n, "has taken a fork");
// 	}
// 	pthread_mutex_unlock(&second->f_lock);
// 	return (1);
// }

int	has_two_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->first->f_lock);
	if (!philo->first->used)
	{
		pthread_mutex_unlock(&philo->first->f_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->first->f_lock);
	pthread_mutex_lock(&philo->second->f_lock);
	if (!philo->second->used)
	{
		pthread_mutex_unlock(&philo->second->f_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->second->f_lock);
	return (1);
}

int	get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->first->f_lock);
	if (!philo->first->used)
	{
		philo->first->used = 1;
		philo->forks_cnt++;
		print_state(philo, curr_time(), "has taken a fork", NRML);
	}
	pthread_mutex_unlock(&philo->first->f_lock);
	if (philo->info->av[PHILOSOPHERS] == 1 || dead(philo) || finished(philo))
	{
		return (0);
	}
	pthread_mutex_lock(&philo->second->f_lock);
	if (!philo->second->used)
	{
		philo->second->used = 1;
		philo->forks_cnt++;
		print_state(philo, curr_time(), "has taken a fork", NRML);
	}
	pthread_mutex_unlock(&philo->second->f_lock);
	return (1);
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->first->f_lock);
	if (philo->first->used)
	{
		philo->first->used = 0;
		philo->forks_cnt--;
	}
	pthread_mutex_unlock(&philo->first->f_lock);
	pthread_mutex_lock(&philo->second->f_lock);
	if (philo->second->used)
	{
		philo->second->used = 0;
		philo->forks_cnt--;
	}
	pthread_mutex_unlock(&philo->second->f_lock);
}
