/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:15:09 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/23 19:28:56 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_num(unsigned int num, int *cnt)
{
	char mod;

	mod = num % 10 + '0';
	if (num >= 10)
	{
		print_num(num / 10, cnt);
		(*cnt)++;
	}
	write(1, &mod, 1);
}

int ft_putnbr(va_list ap)
{
	ssize_t num;
	int cnt;

	cnt = 1;
	num = va_arg(ap, int);
	if (num < 0)
	{
		cnt++;
		write(1, "-", 1);
		num *= -1;
	}
	print_num(num, &cnt);
	return (cnt);
}

int ft_putnbr_u(va_list ap)
{
	unsigned int num;
	int cnt;

	cnt = 1;
	num = va_arg(ap, unsigned int);
	print_num(num, &cnt);
	return (cnt);
}
