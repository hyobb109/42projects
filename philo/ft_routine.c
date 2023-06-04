/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:55:44 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/02 20:54:48 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	print_state(t_philo *philo, long long time, char *message, char *color)
{
	pthread_mutex_lock(&philo->info->print);
	if (dead(philo) || finished(philo))
	{
		pthread_mutex_unlock(&philo->info->print);
		return ;
	}
	// printf("%s%lld %d %s\n", color, get_time_diff(philo->info->start_time), philo->n, message);
	printf("%s%lld %d %s\n", color, (time - philo->start), philo->n, message);
	printf("%s", C_NRML);
	pthread_mutex_unlock(&philo->info->print);
}

void	put_down_forks(t_philo *philo)
{
	// 1명이면
	if (philo->info->av[PHILOSOPHERS] == 1)
	{
		pthread_mutex_unlock(&philo->info->forks[0]);
		return ;
	}
	// 홀수 -> 오른쪽 포크 먼저
	 if (philo->n % 2)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->n - 1]);
		pthread_mutex_unlock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
	}
	// 짝수 -> 왼쪽 포크 먼저
	else
	{
		pthread_mutex_unlock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
		pthread_mutex_unlock(&philo->info->forks[philo->n - 1]);
	}
}

// 포크를 집을 수 있는 상태인지 체크하는 변수 만들기
int	get_forks(t_philo *philo)
{
	// 철학자 1명이면 왼쪽 포크 하나만 듦
	if (philo->info->av[PHILOSOPHERS] == 1)
	{
		pthread_mutex_lock(&philo->info->forks[0]);
		print_state(philo, curr_time(), "has taken a fork", C_NRML);
		return (0);
	}
	// 홀수 -> 왼쪽 포크 먼저
	if (philo->n % 2)
	{
		pthread_mutex_lock(&philo->info->forks[philo->n - 1]);
		print_state(philo, curr_time(), "has taken a fork", C_NRML);
		if (dead(philo) || finished(philo))
		{
			pthread_mutex_unlock(&philo->info->forks[philo->n - 1]);
			return (0);
		}
		pthread_mutex_lock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
		print_state(philo, curr_time(), "has taken a fork", C_NRML);
	}
	// 짝수 -> 오른쪽 포크 먼저
	else
	{
		pthread_mutex_lock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
		print_state(philo, curr_time(), "has taken a fork", C_NRML);
		if (dead(philo) || finished(philo))
		{
			pthread_mutex_unlock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
			return (0);
		}
		pthread_mutex_lock(&philo->info->forks[philo->n - 1]);
		print_state(philo, curr_time(), "has taken a fork", C_NRML);
	}
	// if (dead(philo) || finished(philo))
	// {
	// 	put_down_forks(philo);
	// 	return (0);
	// }

	// long long time = curr_time() - philo->start;
	// pthread_mutex_lock(&philo->info->print);
	// printf("%s%lld %d %s\n", C_NRML, time, philo->n, "has taken a fork");
	// printf("%s%lld %d %s\n", C_NRML, time, philo->n, "has taken a fork");
	// if (dead(philo) || finished(philo))
	// {
	// 	put_down_forks(philo);
	// 	pthread_mutex_unlock(&philo->info->print);
	// 	return (0);
	// }
	// pthread_mutex_unlock(&philo->info->print);
	return (1);
}

// args[DIE]만큼 먹지 않으면 사망 -> 한명이라도 사망하면 시뮬레이션 모두 종료
static void	eat_routine(t_philo *philo)
{
	while (!finished(philo) && !dead(philo))
	{
		if (!get_forks(philo))
			break;
		// 먹기 시작한 시간 체크하고 상태 출력
		pthread_mutex_lock(&philo->info->time);
		// gettimeofday(&philo->last_eat, NULL);
		philo->last = curr_time();
		pthread_mutex_unlock(&philo->info->time);
		pthread_mutex_lock(&philo->info->flag);
		philo->status = EATING;
		pthread_mutex_unlock(&philo->info->flag);
		print_state(philo, philo->last, "is eating", C_GREN);
		// 먹는 시간동안 sleep
		if (!newsleep(philo, philo->info->av[EAT]))
			break;
		// 다 먹으면 포크 순서대로 내려둠
		put_down_forks(philo);
		pthread_mutex_lock(&philo->info->flag);
		philo->status = NOT_EATING;
		pthread_mutex_unlock(&philo->info->flag);
		if (philo->info->ac == 5 && ++philo->eat == philo->info->av[MUST_EAT])
		{
			pthread_mutex_lock(&philo->info->eat_count);
			philo->info->finished++;
			pthread_mutex_unlock(&philo->info->eat_count);
		}
		// 포크 내려두고 자는 시간동안 잠
		print_state(philo, curr_time(), "is sleeping", C_BLUE);
		if (!newsleep(philo, philo->info->av[SLEEP]))
			break;
		// 다 자면 생각 -> 죽는 시간 - (먹는 시간 + 자는 시간)
		print_state(philo, curr_time(), "is thinking", C_YLLW);
		// 전체 철학자 수가 홀수일 때만 유휴시간 50% 만큼 대기 시간 줌 
		if (philo->info->av[PHILOSOPHERS] % 2 == 0)
			continue ;
		if (!newsleep(philo, philo->thinking_time / 2))
			break;
		// usleep(500);
	}
	if (is_eating(philo))
		put_down_forks(philo);
}
// 철학자 루틴 (밥 -> 잠 -> 생각)
// -> 행동할 때 마다 생존여부 체크
void	*start_routine(void *arg)
{
	t_philo	*philo;
	// pthread_t tid = pthread_self();

	philo = (t_philo *)arg;
	if (philo->n % 2 == 0)
	{
		usleep(500);
	} 
	// printf("philosopher %d thread creation, tid: %u\n", info->n, (unsigned int)info->philos[info->n -1].tid);
	eat_routine(philo);
	return (0);
}
