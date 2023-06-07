/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:55:44 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/05 19:27:40 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	print_state(t_philo *philo, long long t, char *msg, char *color)
{
	pthread_mutex_lock(&philo->info->print);
	if (dead(philo) || finished(philo))
	{
		pthread_mutex_unlock(&philo->info->print);
		return ;
	}
	printf("%s%lld %d %s%s\n", color, t - philo->start, philo->n, msg, C_NRML);
	pthread_mutex_unlock(&philo->info->print);
}

static void	check_eating_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->time);
	philo->last = curr_time();
	pthread_mutex_unlock(&philo->info->time);
	pthread_mutex_lock(&philo->info->flag);
	philo->status = EATING;
	pthread_mutex_unlock(&philo->info->flag);
	print_state(philo, philo->last, "is eating", C_GREN);
}

static void	eat_routine(t_philo *philo)
{
	while (!finished(philo) && !dead(philo))
	{
		if (!get_forks(philo))
			break ;
		check_eating_time(philo);
		if (!newsleep(philo, philo->info->av[EAT]))
			break ;
		put_down_forks(philo);
		update_status(&philo->info->flag, &philo->status, NOT_EATING);
		if (philo->info->ac == 5 && ++philo->eat == philo->info->av[MUST_EAT])
			update_status(&philo->info->eat_count, &philo->info->finished, \
			philo->info->finished + 1);
		print_state(philo, curr_time(), "is sleeping", C_BLUE);
		if (!newsleep(philo, philo->info->av[SLEEP]))
			break ;
		print_state(philo, curr_time(), "is thinking", C_YLLW);
		if (philo->info->av[PHILOSOPHERS] % 2 == 0)
			continue ;
		if (!newsleep(philo, philo->thinking_time))
			break ;
	}
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->n % 2 == 0)
		usleep(500);
	eat_routine(philo);
	if (philo->info->av[PHILOSOPHERS] == 1 || is_eating(philo))
		put_down_forks(philo);
	return (0);
}
