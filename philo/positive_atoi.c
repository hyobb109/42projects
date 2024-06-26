/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positive_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 04:50:31 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/24 21:17:34 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	whitespace(char a)
{
	if ((a >= 9 && a <= 13) || a == 32)
		return (1);
	return (0);
}

static int	overflow(long long res, int len)
{
	if (len > 10 || res > 2147483647)
		return (1);
	return (0);
}

int	ft_positive_atoi(const char *str)
{
	long long	res;
	int			i;

	while (whitespace(*str))
		str++;
	if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	res = 0;
	i = 0;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (overflow(res, i) || str[i])
		return (0);
	return (res);
}
