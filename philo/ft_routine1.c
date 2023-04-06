/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:55:44 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/06 21:57:32 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

long long curr_time(void)
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

void	print_state(t_philo *philo, char *message, char *color)
{
	pthread_mutex_lock(&philo->info->print);
	printf("%s", color);
	printf("%lld %d %s\n", get_time_diff(philo->info->start_time), philo->n, message);
	printf("%s", C_NRML);
	pthread_mutex_unlock(&philo->info->print);
}

void	get_forks(t_philo *philo)
{
		// 홀수 -> 왼쪽 포크 먼저
		if (philo->n % 2)
		{
			pthread_mutex_lock(&philo->info->forks[philo->n - 1]);
			pthread_mutex_lock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
		}
		// 짝수 -> 오른쪽 포크 먼저
		else
		{
			pthread_mutex_lock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
			pthread_mutex_lock(&philo->info->forks[philo->n - 1]);
		}
		print_state(philo, "has taken a fork", C_NRML);
		print_state(philo, "has taken a fork", C_NRML);
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

void	newsleep(long long time)
{
	long long	start;

	start = curr_time();
	while (curr_time() - start < time)
		usleep(100);
}

static void	eat_count(t_philo *philo)
{
	// ***모든 철학자가*** info->av[MUST_EAT] 만큼 먹을 때까지 or 모두 살아있을 때 루틴 실행
	while (1)
	{
		get_forks(philo);
		print_state(philo, "is eating", C_GREN);
		// 죽는 시간이 먹는 시간보다 짧으면 사망
		if (philo->info->av[DIE] <= philo->info->av[EAT])
		{
			newsleep(philo->info->av[DIE]);
			// usleep(philo->info->av[DIE] * 1000);
			print_state(philo, "died", C_RED);
			put_down_forks(philo);
			break ;
		}
		else
		{
			newsleep(philo->info->av[EAT]);
			// usleep(philo->info->av[EAT] * 1000);
			// 다 먹은 시간 저장
			gettimeofday(&philo->finish_eating, NULL);
		}
		// 포크 순서대로 내려둠
		put_down_forks(philo);
		if (++philo->eat == philo->info->av[MUST_EAT])
		{
			break;
		}
		print_state(philo, "is sleeping", C_BLUE);
		newsleep(philo->info->av[SLEEP]);
		// usleep(philo->info->av[SLEEP] * 1000);
		print_state(philo, "is thinking", C_YLLW);
		// usleep(500);
		// 다 먹고 나서 args[DIE]만큼 먹지 않으면 사망 -> 한명이라도 사망하면 시뮬레이션 모두 종료
		if (get_time_diff(philo->finish_eating) >= philo->info->av[DIE])
		{
			print_state(philo, "died", C_RED);
		}
	}
}

static void	eat_forever(t_philo *philo)
{
	// 모두 살아있을 때 루틴 반복
	while (1)
	{
		get_forks(philo);
		print_state(philo, "is eating", C_GREN);
		// 죽는 시간이 먹는 시간보다 짧으면 사망
		if (philo->info->av[DIE] <= philo->info->av[EAT])
		{
			newsleep(philo->info->av[DIE]);
			// usleep(philo->info->av[DIE] * 1000);
			print_state(philo, "died", C_RED);
			put_down_forks(philo);
			break ;
		}
		else
		{
			newsleep(philo->info->av[EAT]);
			// usleep(philo->info->av[EAT] * 1000);
			// 다 먹은 시간 저장
			gettimeofday(&philo->finish_eating, NULL);
		}
		// 포크 순서대로 내려둠
		put_down_forks(philo);
		print_state(philo, "is sleeping", C_BLUE);
		newsleep(philo->info->av[SLEEP]);
		// usleep(philo->info->av[SLEEP] * 1000);
		print_state(philo, "is thinking", C_YLLW);
		// usleep(500);
		// 다 먹고 나서 args[DIE]만큼 먹지 않으면 사망 -> 한명이라도 사망하면 시뮬레이션 모두 종료
		if (get_time_diff(philo->finish_eating) >= philo->info->av[DIE])
		{
			print_state(philo, "died", C_RED);
		}
	}
}
// 철학자 루틴 (밥 -> 잠 -> 생각)
// 해야할 것!
// 1. 출력 시간 순서대로 : print에 mutex lock을 걸어라 -> 제대로 됐나 확인 필요
// 2. usleep 시간 쪼개기 : 프로세스 주기 검색해보기
// 3. 먹은 상태, 생존 상태 뮤텍스 걸어서 확인 -> 행동할 때 마다 생존여부 체크
void	*start_routine(void *arg)
{
	t_philo	*philo;
	// pthread_t tid = pthread_self();

	philo = (t_philo *)arg;
	// printf("philosopher %d thread creation, tid: %u\n", info->n, (unsigned int)info->philos[info->n -1].tid);
	// if (philo->n % 2)
	// 	usleep(500);
	if (philo->info->ac == 5)
		eat_count(philo);
	else
		eat_forever(philo);
	return (0);
}
