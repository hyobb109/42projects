/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:08:25 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/05 19:38:18 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

long long	curr_time(void)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	return (curr.tv_sec * 1000 + curr.tv_usec / 1000);
}

int	newsleep(t_philo *philo, long long time)
{
	long long	start;

	start = curr_time();
	while (curr_time() - start < time)
	{
		if (dead(philo) || finished(philo))
		{
			return (0);
		}
		usleep(100);
	}
	return (1);
}
