/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:55:44 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/12 21:15:48 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	print_state(t_philo *philo, long long t, char *msg, char *c)
{
	pthread_mutex_lock(&philo->info->print);
	if (dead(philo) || finished(philo))
	{
		pthread_mutex_unlock(&philo->info->print);
		return ;
	}
	printf("%s%lld %d %s%s\n", c, t - philo->info->start, philo->n, msg, NRML);
	pthread_mutex_unlock(&philo->info->print);
}

static void	eat_routine(t_philo *philo)
{
	while (!finished(philo) && !dead(philo))
	{
		if (!get_forks(philo))
			break ;
		if (!newsleep(philo, philo->info->av[EAT]))
			break ;
		// update_status(&philo->info->flag, &philo->status, NOT_EATING);
		put_down_forks(philo);
		if (philo->info->ac == 5 && ++philo->eat == philo->info->av[MUST_EAT])
			update_status(&philo->info->eat_count, &philo->info->finished, \
			philo->info->finished + 1);
		print_state(philo, curr_time(), "is sleeping", BLUE);
		if (!newsleep(philo, philo->info->av[SLEEP]))
			break ;
		print_state(philo, curr_time(), "is thinking", YLLW);
		if (philo->info->av[PHILOSOPHERS] % 2 == 0)
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
	// if (philo->info->av[PHILOSOPHERS] == 1 || is_eating(philo))
	// 	put_down_forks(philo);
	return (0);
}
