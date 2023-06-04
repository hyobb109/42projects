/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:23:51 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/02 21:03:42 by hyobicho         ###   ########.fr       */
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

int	dead_time(t_philo *philo)
{
	int			flag;

	flag = 0;
	pthread_mutex_lock(&philo->info->time);
	// if (get_time_diff(philo->last_eat) >= philo->info->av[DIE])
	if (curr_time() - philo->last >= philo->info->av[DIE])
	{
		flag = 1;
		// printf("time: %lld, last: %lld\n", curr_time() - philo->last, philo->last);
	}
	pthread_mutex_unlock(&philo->info->time);
	return (flag);
}

void	check_life(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->life);
	if (dead_time(philo))
	{
		// printf("%s%lld %d %s\n", C_RED, get_time_diff(philo->info->start_time), philo->n, "died");
		printf("%s%lld %d %s\n", C_RED, (curr_time() - philo->start), philo->n, "died");
		// print_state(philo, "died", C_RED);
		philo->info->dead = 1;
	}
	pthread_mutex_unlock(&philo->info->life);
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
		usleep(100);
		check_life(&info->philos[i]);
		if (dead(&info->philos[i]) || finished(&info->philos[i]))
		{
			if (is_eating(&info->philos[i]))
				put_down_forks(&info->philos[i]);
			break;
		}
		i = (i + 1) % info->av[PHILOSOPHERS];
	}
}
