/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:08:25 by hyobicho          #+#    #+#             */
/*   Updated: 2023/05/29 22:28:25 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static long long curr_time(void)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return (curr.tv_sec * 1000 + curr.tv_usec / 1000);
}

long long	get_time_diff(struct timeval start)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec - start.tv_sec) * 1000 + (curr.tv_usec - start.tv_usec) / 1000);
}

int	newsleep(t_philo *philo, long long time)
{
	long long	start;

	start = curr_time();
	while (curr_time() - start <= time)
	{
		if (check_life(philo) || finished(philo))
		{
			if (philo->status == EATING)
				put_down_forks(philo);
			return (0);
		}
		usleep(100);
	}
	return (1);
}