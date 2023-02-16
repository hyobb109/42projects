/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_para.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:36:04 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/17 07:41:41 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(char a)
{
	if ((a >= 9 && a <= 13) || a == 32)
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

double	get_offset(char *str, int i, int sign, int p)
{
	t_coord	num;
	double	res;

	num.x = 0;
	num.y = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
		num.x = num.x * 10 + str[i++] - '0';
	if (str[i] == '.')
		while (ft_isdigit(str[++i]))
			num.y += (str[i] - '0') / pow(10, p++);
	if (str[i])
		ft_error(3);
	res = num.x + num.y;
	return (sign * res);
}
