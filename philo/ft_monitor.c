/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:23:51 by hyobicho          #+#    #+#             */
/*   Updated: 2023/05/29 22:27:27 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	check_life(t_philo *philo)
{
	int	dead_flag;

	dead_flag = 0;
	pthread_mutex_lock(&philo->info->life);
	if (get_time_diff(philo->eat_start) >= philo->info->av[DIE])
	{
		print_state(philo, "died", C_RED);
		if (philo->status == EATING)
			put_down_forks(philo);
		else if (philo->info->av[PHILOSOPHERS] == 1)
			pthread_mutex_unlock(&philo->info->forks[0]);
		// pthread_mutex_lock(&philo->info->flag);
		// philo->info->dead = 1;
		// pthread_mutex_unlock(&philo->info->flag);
		dead_flag = 1;
	}
	pthread_mutex_unlock(&philo->info->life);
	return (dead_flag);
}

int	finished(t_philo *philo)
{
	int	eat_flag;

	eat_flag = 0;
	if (philo->info->ac == 5)
	{
		pthread_mutex_lock(&philo->info->eat_count);
		if (philo->info->finished == philo->info->av[PHILOSOPHERS])
			eat_flag = 1;
		pthread_mutex_unlock(&philo->info->eat_count);
	}
	return (eat_flag);
}

void	monitor_threads(t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		if (check_life(&info->philos[i]) || finished(&info->philos[i]))
		{
			break ;
		}
		i = (i + 1) % info->av[PHILOSOPHERS];
	}
}