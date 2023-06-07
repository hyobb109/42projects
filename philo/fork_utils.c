/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:27:10 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/05 19:29:09 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	pickup(t_philo *philo, pthread_mutex_t *f, pthread_mutex_t *s)
{
	pthread_mutex_lock(f);
	print_state(philo, curr_time(), "has taken a fork", C_NRML);
	if (dead(philo) || finished(philo))
	{
		pthread_mutex_unlock(f);
		return (0);
	}
	pthread_mutex_lock(s);
	print_state(philo, curr_time(), "has taken a fork", C_NRML);
	return (1);
}

int	get_forks(t_philo *philo)
{
	if (philo->info->av[PHILOSOPHERS] == 1)
	{
		pthread_mutex_lock(&philo->info->forks[0].f_lock);
		print_state(philo, curr_time(), "has taken a fork", C_NRML);
		return (0);
	}
	if (philo->n % 2)
		return (pickup(philo, &philo->info->forks[philo->left].f_lock, \
		&philo->info->forks[philo->right].f_lock));
	return (pickup(philo, &philo->info->forks[philo->right].f_lock, \
		&philo->info->forks[philo->left].f_lock));
}

void	put_down_forks(t_philo *philo)
{
	if (philo->info->av[PHILOSOPHERS] == 1)
	{
		pthread_mutex_unlock(&philo->info->forks[0].f_lock);
		return ;
	}
	if (philo->n % 2)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->left].f_lock);
		pthread_mutex_unlock(&philo->info->forks[philo->right].f_lock);
	}
	else
	{
		pthread_mutex_unlock(&philo->info->forks[philo->right].f_lock);
		pthread_mutex_unlock(&philo->info->forks[philo->left].f_lock);
	}
}
