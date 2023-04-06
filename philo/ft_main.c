/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:43:56 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/06 21:57:15 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

//// !!! philo 디렉토리 안에 넣기 !!!

void	check_leak()
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;
	
	// atexit(check_leak);
	// 인자 체크
	if (check_args(argc, argv, &info) == INVALID)
		return (ft_error("Error: Invalid Arguments\n"));
	// init info
	if (init_info(&info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
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
		// printf("thread %d joined\n", i + 1);
	}
	// destroy_mutexes()
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
