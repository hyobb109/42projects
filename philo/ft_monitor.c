/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:23:51 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/01 22:17:07 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	check_life(t_philo *philo)
{
	// pthread_mutex_lock(&philo->info->life);
	pthread_mutex_lock(&philo->info->time);
	if (get_time_diff(philo->eat_start) >= philo->info->av[DIE])
	{
		pthread_mutex_unlock(&philo->info->time);
		printf("%s%lld %d %s\n", C_RED, get_time_diff(philo->info->start_time), philo->n, "died");
		// print_state(philo, "died", C_RED);
		if (philo->status == EATING)
			put_down_forks(philo);
		else if (philo->info->av[PHILOSOPHERS] == 1)
			pthread_mutex_unlock(&philo->info->forks[0]);
		// pthread_mutex_lock(&philo->info->flag);
		philo->info->dead = 1;
		// pthread_mutex_unlock(&philo->info->flag);
	}
	else
		pthread_mutex_unlock(&philo->info->time);
	// pthread_mutex_unlock(&philo->info->life);
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

void	monitor_threads(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&info->life);
		check_life(&info->philos[i]);
		pthread_mutex_unlock(&info->life);
		if (dead(&info->philos[i]) || finished(&info->philos[i]))
			break;
		i = (i + 1) % info->av[PHILOSOPHERS];
	}
}
