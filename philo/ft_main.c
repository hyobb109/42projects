/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:43:56 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/30 21:53:59 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

//// !!! philo 디렉토리 안에 넣기 !!!

//테스트테스트
void time_test()
{
	struct timeval	start_time;
	struct timeval	end_time;
	
	gettimeofday(&start_time, NULL);
	printf("%ld %d\n", start_time.tv_sec, start_time.tv_usec);
	// usleep(1000000);
	gettimeofday(&end_time, NULL);
	printf("%ld %d\n", end_time.tv_sec, end_time.tv_usec);
}

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

int check_args(int argc, char **argv, t_args *args)
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

void	*start_routine(void *arg)
{
	t_philo	*philo;
	// pthread_t tid = pthread_self();

	philo = (t_philo *)arg;
	usleep(1000000);
	printf("philosopher %d thread creation, tid: %u\n", philo->n, (unsigned int)philo->tid);
	printf("%lld %d has taken a fork\n", get_time(philo->start_time), philo->n);
	// args[DIE]만큼 먹지 않으면 사망
	return 0;
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
	t_args		args;
	t_philo		*philos;
	struct timeval	curr;
	
	// atexit(check_leak);
	// 인자 체크
	if (check_args(argc, argv, &args) == INVALID)
		return (ft_error("Error: Invalid Arguments\n"));
	// 인자 출력 테스트
	// printf("args.ac = %d\n", args.ac);
	// for (int i = 0; i < args.ac; i++)
	// {
	// 	printf("args[%d] = %d\n", i, args.av[i]);
	// }
	philos = (t_philo *)malloc(sizeof(t_philo) * args.av[PHILOSOPHERS]);
	if (philos == NULL)
		return (ft_error("Error: malloc failed\n"));
	gettimeofday(&curr, NULL);
	int	i = -1;
	while (++i < args.av[PHILOSOPHERS])
	{
		philos[i].n = i + 1;
		philos[i].args = args;
		philos[i].start_time = curr;
		if (pthread_create(&philos[i].tid, NULL, start_routine, &philos[i]) != 0)
			return (free_philo(philos, "Error: pthread_create failed\n"));
	}
	//  생성된 스레드가 종료될 때까지 기다림s != 0)
	i = -1;
	while(++i < args.av[PHILOSOPHERS])
	{
		if (pthread_join(philos[i].tid, NULL) != 0)
			return (free_philo(philos, "Error: pthread_join failed\n"));
		printf("thread %d joined\n", i + 1);
	}
	free(philos);
	return (EXIT_SUCCESS);
}
