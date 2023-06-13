/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:55:44 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/13 17:54:07 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	print_state(t_philo *philo, char *msg, char *color)
{
	long long	curr;

	pthread_mutex_lock(&philo->info->print);
	curr = curr_time() - philo->info->start;
	if (dead(philo) || finished(philo))
	{
		pthread_mutex_unlock(&philo->info->print);
		return ;
	}
	printf("%s%lld %d %s%s\n", color, curr, philo->n, msg, NRML);
	pthread_mutex_unlock(&philo->info->print);
}

int	count_eat(t_philo *philo)
{
	int	flag;

	flag = 0;
	philo->eat++;
	pthread_mutex_lock(&philo->info->eat_count);
	if (philo->eat == philo->info->av[MUST_EAT])
	{
		philo->info->finished++;
	}
	pthread_mutex_unlock(&philo->info->eat_count);
	return (flag);
}

static void	eat_routine(t_philo *philo)
{
	while (!finished(philo) && !dead(philo))
	{
		if (!get_forks(philo))
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
