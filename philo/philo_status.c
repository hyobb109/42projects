/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:01:34 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/05 17:02:00 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	is_eating(t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&philo->info->flag);
	if (philo->status == EATING)
		flag = 1;
	pthread_mutex_unlock(&philo->info->flag);
	return (flag);
}

int	dead(t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&philo->info->life);
	if (philo->info->dead == 1)
	{
		flag = 1;
	}
	pthread_mutex_unlock(&philo->info->life);
	return (flag);
}

int	finished(t_philo *philo)
{
	int	flag;

	flag = 0;
	if (philo->info->ac == 5)
	{
		pthread_mutex_lock(&philo->info->eat_count);
		if (philo->info->finished == philo->info->av[PHILOSOPHERS])
			flag = 1;
		pthread_mutex_unlock(&philo->info->eat_count);
	}
	return (flag);
}
