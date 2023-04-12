/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:23:51 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/12 22:23:52 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	check_life(t_philo *philo)
{
	long long tmp;

	pthread_mutex_lock(&philo->info->life);
	if ((tmp = get_time_diff(philo->eat_start)) >= philo->info->av[DIE])
	{
		printf("%lld\n", tmp);
		print_state(philo, "died", C_RED);
		if (philo->status == EATING)
			put_down_forks(philo);
		else if (philo->info->av[PHILOSOPHERS] == 1)
			pthread_mutex_unlock(&philo->info->forks[0]);
		philo->info->dead = 1;
	}
	pthread_mutex_unlock(&philo->info->life);
}

void	monitor_threads(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		check_life(&info->philos[i]);
		if (info->finished == info->av[PHILOSOPHERS])
		{
			break;
		}
		if (info->dead)
		{
			break;
		}
		i = (i + 1) % info->av[PHILOSOPHERS];
	}
}
