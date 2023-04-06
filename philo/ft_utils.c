/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:33:17 by hyobicho          #+#    #+#             */
/*   Updated: 2023/04/06 21:55:09 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == 0)
		return (0);
	while (s[len])
		len++;
	return (len);
}

static void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

int	ft_error(char *message)
{
	ft_putstr_fd(message, 2);
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

int	free_philo(t_philo *philos, char *message)
{
	free(philos);
	return (ft_error(message));
}
