/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:55:44 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/13 21:41:57 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	print_state(t_philo *philo, char *message, char *color)
{
	pthread_mutex_lock(&philo->info->print);
	if (philo->info->dead)
		return ;
	printf("%s", color);
	printf("%lld %d %s\n", get_time_diff(philo->info->start_time), philo->n, message);
	printf("%s", C_NRML);
	pthread_mutex_unlock(&philo->info->print);
}

void	put_down_forks(t_philo *philo)
{
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

int	get_forks(t_philo *philo)
{
	// 철학자 1명이면 왼쪽 포크 하나만 듦
	if (philo->info->av[PHILOSOPHERS] == 1)
	{
		pthread_mutex_lock(&philo->info->forks[0]);
		print_state(philo, "has taken a fork", C_NRML);
		return (0);
	}
	// 홀수 -> 왼쪽 포크 먼저
	if (philo->n % 2)
	{
		pthread_mutex_lock(&philo->info->forks[philo->n - 1]);
		if (philo->info->dead)
		{
			pthread_mutex_unlock(&philo->info->forks[philo->n - 1]);
			return (0);
		}
		pthread_mutex_lock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
		if (philo->info->dead)
		{
			put_down_forks(philo);
			return (0);
		}
	}
	// 짝수 -> 오른쪽 포크 먼저
	else
	{
		pthread_mutex_lock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
		if (philo->info->dead)
		{
			pthread_mutex_unlock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
			return (0);
		}
		pthread_mutex_lock(&philo->info->forks[philo->n - 1]);
		if (philo->info->dead)
		{
			put_down_forks(philo);
			return (0);
		}
	}
	print_state(philo, "has taken a fork", C_NRML);
	print_state(philo, "has taken a fork", C_NRML);
	return (1);
}

static void	eat_count(t_philo *philo)
{
	// printf("finished: %d\n", philo->info->finished);
	// ***모든 철학자가*** info->av[MUST_EAT] 만큼 먹을 때까지 or 모두 살아있을 때 루틴 실행
	while (philo->info->finished != philo->info->av[PHILOSOPHERS] && !philo->info->dead)
	{
		if (!get_forks(philo))
			break;
		philo->status = EATING;
		pthread_mutex_lock(&philo->info->time);
		gettimeofday(&philo->eat_start, NULL);
		pthread_mutex_unlock(&philo->info->time);
		print_state(philo, "is eating", C_GREN);
		if (!newsleep(philo, philo->info->av[EAT]))
			break;
		put_down_forks(philo);
		if (++philo->eat == philo->info->av[MUST_EAT])
		{
			pthread_mutex_lock(&philo->info->eat_count);
			philo->info->finished++;
			pthread_mutex_unlock(&philo->info->eat_count);
		}
		philo->status = SLEEPING;
		print_state(philo, "is sleeping", C_BLUE);
		if (!newsleep(philo, philo->info->av[SLEEP]))
			break;
		philo->status = THINKING;
		print_state(philo, "is thinking", C_YLLW);
		if (philo->info->av[PHILOSOPHERS] % 2 == 0)
			continue ;
		if (!newsleep(philo, philo->idle_time / 10))
			break ;
		// usleep(500);
		// printf("must eat: %d, philo %d eat %d times, info->finished: %d\n", philo->info->av[MUST_EAT], philo->n, philo->eat, philo->info->finished);
	}
}

static void	eat_forever(t_philo *philo)
{
	// 모두 살아있을 때 루틴 반복
	// args[DIE]만큼 먹지 않으면 사망 -> 한명이라도 사망하면 시뮬레이션 모두 종료
	while (!philo->info->dead)
	{
		// 포크 집음
		if (!get_forks(philo))
			break;
		philo->status = EATING;
		// 먹기 시작한 시간 체크하고 상태 출력
		 pthread_mutex_lock(&philo->info->time);
		gettimeofday(&philo->eat_start, NULL);
		 pthread_mutex_unlock(&philo->info->time);
		print_state(philo, "is eating", C_GREN);
		// 먹는 시간동안 sleep
		if (!newsleep(philo, philo->info->av[EAT]))
			break;
		// 다 먹으면 포크 순서대로 내려둠
		put_down_forks(philo);
		// 포그 내려두고 자는 시간동안 잠
		philo->status = SLEEPING;
		print_state(philo, "is sleeping", C_BLUE);
		if (!newsleep(philo, philo->info->av[SLEEP]))
			break;
		// 다 자면 생각 -> 죽는 시간 - (먹는 시간 + 자는 시간)
		philo->status = THINKING;
		print_state(philo, "is thinking", C_YLLW);
		// 전체 철학자 수가 홀수일 때만 유휴시간 10% 만큼 대기 시간 줌 
		if (philo->info->av[PHILOSOPHERS] % 2 == 0)
			continue ;
		if (!newsleep(philo, philo->idle_time / 10))
			break;
		// usleep(500);
	}
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
		usleep(100);
	} 
	// printf("philosopher %d thread creation, tid: %u\n", info->n, (unsigned int)info->philos[info->n -1].tid);
	if (philo->info->ac == 5)
		eat_count(philo);
	else
		eat_forever(philo);
	return (0);
}
