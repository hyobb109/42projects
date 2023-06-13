/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:01:34 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/13 18:06:27 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

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
		if (philo->info->finished == philo->info->av[PHILOS])
			flag = 1;
		pthread_mutex_unlock(&philo->info->eat_count);
	}
	return (flag);
}
