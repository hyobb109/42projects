/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:33:17 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/12 19:48:11 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_error(char *message)
{
	size_t	len;

	len = 0;
	if (!message)
		return (EXIT_FAILURE);
	while (message[len])
		len++;
	write(2, message, len);
	return (EXIT_FAILURE);
}

int check_args(int argc, char **argv, t_info *args)
{
	int	i;
	// 개수 체크
	if (argc < 5 || argc > 6)
		return (INVALID);
	args->ac = argc - 1;
	// 숫자 유효성 체크 -> 양수 아닌 것 에러
	i = -1;
	while (++i < args->ac)
	{
		args->av[i] = ft_positive_atoi(argv[i + 1]);
		if (args->av[i] <= 0)
			return	(INVALID);
	}
	return (VALID);
}

int	free_all(t_info	*info, char *message)
{
	free(info->philos);
	free(info->forks);
	return (ft_error(message));
}