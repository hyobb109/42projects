/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:55:44 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/10 21:55:14 by hyobicho         ###   ########.fr       */
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

int	put_down_forks(t_philo *philo)
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
	return (1);
}

void	check_life(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->lock2);
	if (get_time_diff(philo->eat_start) >= philo->info->av[DIE])
	{
		print_state(philo, "died", C_RED);
		if (philo->status == EATING)
			put_down_forks(philo);
		philo->info->dead = 1;
	}
	pthread_mutex_unlock(&philo->info->lock2);
}

int	get_forks(t_philo *philo)
{
	if (philo->info->dead)
		return (0);
	// 홀수 -> 왼쪽 포크 먼저
	if (philo->info->av[PHILOSOPHERS] == 1)
	{
		pthread_mutex_lock(&philo->info->forks[0]);
		print_state(philo, "has taken a fork", C_NRML);
		return (0);
	}
	if (philo->n % 2)
	{
		// check_life(philo);
		pthread_mutex_lock(&philo->info->forks[philo->n - 1]);
		if (philo->info->dead)
		{
			pthread_mutex_unlock(&philo->info->forks[philo->n - 1]);
			return (1);
		}
		// check_life(philo);
		pthread_mutex_lock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
		if (philo->info->dead)
		{
			pthread_mutex_unlock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
			return (0);
		}
	}
	// 짝수 -> 오른쪽 포크 먼저
	else
	{
		// check_life(philo);
		pthread_mutex_lock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
		if (philo->info->dead)
		{
			pthread_mutex_unlock(&philo->info->forks[philo->n % philo->info->av[PHILOSOPHERS]]);
			return (0);
		}
		pthread_mutex_lock(&philo->info->forks[philo->n - 1]);
		if (philo->info->dead)
		{
			pthread_mutex_unlock(&philo->info->forks[philo->n - 1]);
			return (0);
		}
	}
	print_state(philo, "has taken a fork", C_NRML);
	print_state(philo, "has taken a fork", C_NRML);
	return (1);
}

int	newsleep(t_philo *philo, long long time)
{
	long long	start;

	start = curr_time();
	while (curr_time() - start < time)
	{
		usleep(100);
		if (philo->info->dead)
			return (0);
	}
	return (1);
}

static void	eat_count(t_philo *philo)
{
	// printf("finished: %d\n", philo->info->finished);
	// ***모든 철학자가*** info->av[MUST_EAT] 만큼 먹을 때까지 or 모두 살아있을 때 루틴 실행
	while (!philo->info->finished && !philo->info->dead)
	{
		if (!get_forks(philo))
			break;
	
		philo->status = EATING;
		
		// 먹기 시작한 시간 저장
		pthread_mutex_lock(&philo->info->lock);
		gettimeofday(&philo->eat_start, NULL);
		pthread_mutex_unlock(&philo->info->lock);
		print_state(philo, "is eating", C_GREN);
		// 죽는 시간이 먹는 시간보다 짧으면 사망
		if (!newsleep(philo, philo->info->av[EAT]))
			break;		
		// usleep(philo->info->av[EAT] * 1000);
		// 포크 순서대로 내려둠
		if (!put_down_forks(philo))
			break;
		if (++philo->eat == philo->info->av[MUST_EAT])
		{
			pthread_mutex_lock(&philo->info->lock);
			philo->info->finished++;
			pthread_mutex_unlock(&philo->info->lock);
		}
		if (philo->info->dead)
			break;
		philo->status = SLEEPING;
		print_state(philo, "is sleeping", C_BLUE);
		newsleep(philo, philo->info->av[SLEEP]);
		if (philo->info->dead)
			break;

		// usleep(philo->info->av[SLEEP] * 1000);
		philo->status = THINKING;
		print_state(philo, "is thinking", C_YLLW);
		// usleep(500);
		// 이전 식사 시작시간부터 args[DIE]만큼 먹지 않으면 사망 -> 한명이라도 사망하면 시뮬레이션 모두 종료
		// check_life(philo);
	}
}

static void	eat_forever(t_philo *philo)
{
	// 모두 살아있을 때 루틴 반복
	while (!philo->info->dead)
	{
		// 포크 집음
		if (!get_forks(philo))
			break;
		philo->status = EATING;
		// 먹기 시작한 시간 체크하고 상태 출력
		pthread_mutex_lock(&philo->info->lock);
		gettimeofday(&philo->eat_start, NULL);
		pthread_mutex_unlock(&philo->info->lock);
		print_state(philo, "is eating", C_GREN);
		// 죽는 시간이 먹는 시간보다 짧으면 사망 !!
		// 먹는 시간동안 sleep
		if (!newsleep(philo, philo->info->av[EAT]))
			break;

		// usleep(philo->info->av[EAT] * 1000);
		// 다 먹으면 포크 순서대로 내려둠
		if (!put_down_forks(philo))
			break;
		// 포그 내려두고 자는 시간동안 잠
		philo->status = SLEEPING;
		print_state(philo, "is sleeping", C_BLUE);
		if (!newsleep(philo, philo->info->av[SLEEP]))
			break;
		// usleep(philo->info->av[SLEEP] * 1000);

		// 다 자면 생각
		philo->status = THINKING;
		print_state(philo, "is thinking", C_YLLW);
		// usleep(500);
		// args[DIE]만큼 먹지 않으면 사망 -> 한명이라도 사망하면 시뮬레이션 모두 종료
	}
}
// 철학자 루틴 (밥 -> 잠 -> 생각)
// -> 행동할 때 마다 생존여부 체크
void	*start_routine(void *arg)
{
	t_philo	*philo;
	// pthread_t tid = pthread_self();

	philo = (t_philo *)arg;
	// printf("philosopher %d thread creation, tid: %u\n", info->n, (unsigned int)info->philos[info->n -1].tid);
	if (philo->info->ac == 5)
		eat_count(philo);
	else
		eat_forever(philo);
	return (0);
}
