/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:15:09 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/22 16:31:01 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprint.h"

static void	print_num(long long num, size_t *cnt)
{
	long long	mod;

	mod = num % 10 + '0';
	if (num >= 10)
	{
		print_num(num / 10, cnt);
		(*cnt)++;
	}
	write(1, &mod, 1);
}

size_t	ft_putnbr(va_list ap)
{
	long long	num;
	size_t		cnt;

	cnt = 1;
	num = (long long)ap;
	if (num < 0)
	{
		cnt++;
		write(1, "-", 1);
		num *= -1;
	}
	print_num(num, &cnt);
	return (cnt);
}

size_t	ft_putunbr(va_list ap)
{
	size_t			cnt;
	unsigned int	n;

	n = (unsigned int)ap;
	cnt = 1;
	print_num((long long)n, &cnt);
	return (cnt);
}
