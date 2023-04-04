/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:43:56 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/04 20:57:34 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

//// !!! philo 디렉토리 안에 넣기 !!!

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == 0)
		return (0);
	while (s[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

int check_args(int argc, char **argv, t_info *args)
{
	int	i;
	// 개수 체크
	if (argc < 5 || argc > 6)
		return (INVALID);
	args->ac = argc - 1;
	// 인자 수만큼 할당
	// args->av = (int *)malloc(sizeof(int) * args->ac);
	// if (args->av == NULL)
	// 	return (INVALID);
	// 숫자 유효성 체크 -> 양수 아닌 것 에러
	i = -1;
	while (++i < args->ac)
	{
		args->av[i] = ft_positive_atoi(argv[i + 1]);
		if (args->av[i] == 0)
			return	(INVALID);
	}
	return (VALID);
}

long long	get_time(struct timeval start)
{
	struct timeval curr;

	gettimeofday(&curr, NULL);
	return ((curr.tv_sec - start.tv_sec) * 1000 + (curr.tv_usec - start.tv_usec) / 1000);
}

void	print_state(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->info->print);
	printf("%lld %d %s\n", get_time(philo->info->start_time), philo->n, message);
	pthread_mutex_unlock(&philo->info->print);
}

void	get_forks(t_philo *philo)
{
		// 홀수 -> 왼쪽 포크 먼저
		if (philo->n % 2)
		{
			pthread_mutex_lock(&philo->info->forks[philo->n - 1]);
			pthread_mutex_lock(&philo->info->forks[philo->n]);
		}
		// 짝수 -> 오른쪽 포크 먼저
		else
		{
			pthread_mutex_lock(&philo->info->forks[philo->n]);
			pthread_mutex_lock(&philo->info->forks[philo->n - 1]);
		}
		print_state(philo, "has taken a fork");
		print_state(philo, "has taken a fork");
}

// 철학자 루틴 (밥 -> 잠 -> 생각)
// 해야할 것!
// 1. 출력 시간 순서대로 : print에 mutex lock을 걸어라 -> 제대로 됐나 확인 필요
// 2. usleep 시간 쪼개기 : 프로세스 주기 검색해보기
void	*start_routine(void *arg)
{
	t_philo	*philo;
	// pthread_t tid = pthread_self();

	philo = (t_philo *)arg;
	philo->exit_flag = 0;
	// printf("philosopher %d thread creation, tid: %u\n", info->n, (unsigned int)info->philos[info->n -1].tid);
	while (1)
	{
		get_forks(philo);
		print_state(philo, "is eating");
		// 죽는 시간이 먹는 시간보다 짧으면 사망
		if (philo->info->av[DIE] < philo->info->av[EAT])
		{
			usleep(philo->info->av[DIE] * 1000);
			print_state(philo, "died");
			philo->exit_flag = 1;
			// 포크 내려둠
			pthread_mutex_unlock(&philo->info->forks[philo->n - 1]);
			pthread_mutex_unlock(&philo->info->forks[philo->n]);
			break ;
		}
		else
		{
			usleep(philo->info->av[EAT] * 1000);
			// 다 먹은 시간 저장
			gettimeofday(&philo->finish_eating, NULL);
		}
		// 포크 내려둠
		pthread_mutex_unlock(&philo->info->forks[philo->n - 1]);
		pthread_mutex_unlock(&philo->info->forks[philo->n]);
		// 먹는 횟수 제한 있을 때
		if (++philo->eat == philo->info->av[MUST_EAT] && philo->info->ac == 5)
		{
			// info->av[MUST_EAT] 만큼 먹으면 종료
			philo->exit_flag = 1;
			break ;
		}
		print_state(philo, "is sleeping");
		usleep(philo->info->av[SLEEP] * 1000);
		print_state(philo, "is thinking");
		// 다 먹고 나서 args[DIE]만큼 먹지 않으면 사망 -> 한명이라도 사망하면 시뮬레이션 모두 종료
		if (get_time(philo->finish_eating) >= philo->info->av[DIE])
		{
			print_state(philo, "died");
			philo->exit_flag = 1;
			break ;
		}
	}
	return (0);
}

int	ft_error(char *message)
{
	ft_putstr_fd(message, 2);
	return (EXIT_FAILURE);
}

void	check_leak()
{
	system("leaks philo");
}

int	free_philo(t_philo *philos, char *message)
{
	free(philos);
	return (ft_error(message));
}

int	main(int argc, char **argv)
{
	t_info		info;
	int	i;
	
	// atexit(check_leak);
	// 인자 체크
	if (check_args(argc, argv, &info) == INVALID)
		return (ft_error("Error: Invalid Arguments\n"));
	// init info
	info.philos = (t_philo *)malloc(sizeof(t_philo) * info.av[PHILOSOPHERS]);
	if (info.philos == NULL)
		return (ft_error("Error: malloc failed\n"));
	info.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info.av[PHILOSOPHERS]);
	if (info.forks == NULL)
		return (free_philo(info.philos, "Error: fork malloc failed\n"));
	pthread_mutex_init(&info.print, NULL);
	i = -1;
	while (++i < info.av[PHILOSOPHERS])
	{
		if (pthread_mutex_init(&info.forks[i], NULL) != 0)
		{
			free(info.forks);
			return (free_philo(info.philos, "Error: mutex init failed\n"));
		}
	}
	gettimeofday(&info.start_time, NULL);
	i = -1;
	while (++i < info.av[PHILOSOPHERS])
	{
		info.philos[i].n = i + 1;
		info.philos[i].eat = 0;
		info.philos[i].info = &info;
		if (pthread_create(&info.philos[i].tid, NULL, start_routine, &info.philos[i]) != 0)
			return (free_philo(info.philos, "Error: pthread_create failed\n"));
	}
	//  생성된 스레드가 종료될 때까지 기다림s != 0)
	i = -1;
	while(++i < info.av[PHILOSOPHERS])
	{
		if (pthread_join(info.philos[i].tid, NULL) != 0)
			return (free_philo(info.philos, "Error: pthread_join failed\n"));
		if (info.philos[i].exit_flag)
			break ;
		// printf("thread %d joined\n", i + 1);
	}
	i = -1;
	while (++i < info.av[PHILOSOPHERS])
	{
		pthread_mutex_destroy(&info.forks[i]);
	}
	pthread_mutex_destroy(&info.print);
	free(info.philos);
	free(info.forks);
	return (EXIT_SUCCESS);
}
