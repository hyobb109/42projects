/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:43:56 by hyobicho          #+#    #+#             */
/*   Updated: 2023/06/05 19:47:55 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

//// !!! philo 디렉토리 안에 넣기 !!!

int	main(int argc, char **argv)
{
	t_info	info;

	if (check_args(argc, argv, &info) == INVALID)
		return (ft_error("Error: Invalid Arguments\n"));
	if (init_info(&info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (create_threads(&info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	monitor_threads(&info);
	if (join_threads(&info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (destroy_mutexes(&info) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(info.philos);
	free(info.forks);
	return (EXIT_SUCCESS);
}
