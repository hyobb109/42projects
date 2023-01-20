/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 04:50:31 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/20 20:07:43 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(char a)
{
	if ((a >= 9 && a <= 13) || a == 32)
		return (1);
	return (0);
}

static int	overflow(long long res, int len, int flag)
{
	if (flag)
		len--;
	if (len > 10 || res < -2147483648 || res > 2147483647)
		return (1);
	return (0);
}

static int	check_str(const char *str, int *sign, int *flag)
{
	int	i;

	i = 0;
	while (whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		*flag = 1;
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	int			i;
	int			flag;

	res = 0;
	sign = 1;
	flag = 0;
	i = check_str(str, &sign, &flag);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (overflow(sign * res, i, flag) || str[i])
		ft_error();
	return (res * sign);
}
