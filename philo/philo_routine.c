/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:55:44 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/14 16:06:12 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	print_state(t_philo *philo, char *msg, char *color)
{
	long long	curr;

	pthread_mutex_lock(&philo->info->print);
	if (dead(philo) || finished(philo))
	{
		pthread_mutex_unlock(&philo->info->print);
		return ;
	}
	curr = curr_time() - philo->info->start;
	printf("%s%lld %d %s%s\n", color, curr, philo->n, msg, NRML);
	pthread_mutex_unlock(&philo->info->print);
}

static void	count_eat(t_philo *philo)
{
	philo->eat++;
	pthread_mutex_lock(&philo->info->eat_count);
	if (philo->eat == philo->info->av[MUST_EAT])
	{
		philo->info->finished++;
	}
	pthread_mutex_unlock(&philo->info->eat_count);
}

static int	check_eating_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print);
	pthread_mutex_lock(&philo->info->time);
	philo->last = curr_time();
	pthread_mutex_unlock(&philo->info->time);
	printf("%s%lld %d is eating%s\n", GREEN, \
	philo->last - philo->info->start, philo->n, NRML);
	if (dead(philo) || finished(philo))
	{
		pthread_mutex_unlock(&philo->info->print);
		return (0);
	}
	pthread_mutex_unlock(&philo->info->print);
	return (1);
}

static void	eat_routine(t_philo *philo)
{
	while (!finished(philo) && !dead(philo))
	{
		if (!get_forks(philo))
			break ;
		if (!check_eating_time(philo))
			break ;
		if (!newsleep(philo, philo->info->av[EAT]))
			break ;
		put_down_forks(philo);
		if (philo->info->ac == 5)
			count_eat(philo);
		print_state(philo, "is sleeping", BLUE);
		if (!newsleep(philo, philo->info->av[SLEEP]))
			break ;
		print_state(philo, "is thinking", YLLW);
		if (philo->info->av[PHILOS] % 2 == 0)
			continue ;
		if (!newsleep(philo, philo->thinking))
			break ;
	}
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->info->flag);
	pthread_mutex_unlock(&philo->info->flag);
	if (philo->n % 2 == 0)
		usleep(500);
	eat_routine(philo);
	return (0);
}
