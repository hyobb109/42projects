/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:23:51 by hyobicho          #+#    #+#             */
/*   Updated: 2023/05/25 19:15:45 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	check_life(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->life);
	if (get_time_diff(philo->eat_start) >= philo->info->av[DIE])
	{
		print_state(philo, "died", C_RED);
		if (philo->status == EATING)
			put_down_forks(philo);
		else if (philo->info->av[PHILOSOPHERS] == 1)
			pthread_mutex_unlock(&philo->info->forks[0]);
		// pthread_mutex_lock(&philo->info->flag);
		philo->info->dead = 1;
		// pthread_mutex_unlock(&philo->info->flag);
	}
	pthread_mutex_unlock(&philo->info->life);
}

int	dead(t_info *info)
{
	int	flag;

	flag = 0;
	// pthread_mutex_lock(&info->flag);
	if (info->dead)
		flag = 1;
	// pthread_mutex_unlock(&info->flag);
	return (flag);
}

int	finished(t_info *info)
{
	int	flag;

	flag = 0;
	if (info->ac == 5)
	{
		pthread_mutex_lock(&info->eat_count);
		if (info->finished == info->av[PHILOSOPHERS])
			flag = 1;
		pthread_mutex_unlock(&info->eat_count);
	}
	return (flag);
}

void	monitor_threads(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		check_life(&info->philos[i]);
		if (dead(info) || finished(info))
			break;
		i = (i + 1) % info->av[PHILOSOPHERS];
	}
}
