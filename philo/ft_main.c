/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:43:56 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/28 22:32:13 by hyobicho         ###   ########.fr       */
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
	usleep(1000000);
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

int check_args(int argc, char **argv, t_philo *info)
{
	int	i;
	// 개수 체크
	if (argc < 5 || argc > 6)
		return (INVALID);
	// 숫자 유효성 체크 -> 양수 아닌 것 에러
	i = 0;
	while (++i < argc)
	{
		info->args[i - 1] = ft_positive_atoi(argv[i]);
		if (info->args[i - 1] == 0)
			return (INVALID);
	}
	return (VALID);
}

void	*start_routine(void *arg)
{
	t_philo	*info;

	info = (t_philo *)arg;
	printf("philosopher %d thread creation\n", info->n);
	return 0;
}

int	ft_error(char *message)
{
	ft_putstr_fd(message, 2);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_philo	info;

	// 인자 체크
	if (check_args(argc, argv, &info) == INVALID)
		return (ft_error("Error: Invalid Arguments\n"));
	/* 인자 출력 테스트
	for (int i = 0; i < 5; i++)
	{
		printf("args[%d] = %d\n", i, info.args[i]);
	}*/

	info.n = 0;
	while (++info.n <= info.args[PHILOSOPHERS])
	{
		if (pthread_create(&info.tid, NULL, start_routine, &info) != 0)
			return (ft_error("Error: pthread_create failed\n"));
		//  생성된 스레드가 종료될 때까지 기다림
		if (pthread_join(info.tid, NULL) != 0)
			return (ft_error("Error: pthread_join failed\n"));
		printf("thread joined\n");
	}
	return (EXIT_SUCCESS);
}

