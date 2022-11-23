/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:47:20 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/23 19:29:21 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_addr(unsigned long long x, int *cnt, const char *hex)
{
	char	mod;

	mod = hex[x % 16];
	if (x >= 16)
	{
		print_addr(x / 16, cnt, hex);
		(*cnt)++;
	}
	write(1, &mod, 1);
}

int	ft_putaddr(va_list ap)
{
	int		cnt;
	void	*addr;

	addr = va_arg(ap, void *);
	cnt = 3;
	write(1, "0x", 2);
	print_addr((unsigned long long)addr, &cnt, "0123456789abcdef");
	return (cnt);
}

static void	print_hex(unsigned int x, int *cnt, const char *hex)
{
	char	mod;

	mod = hex[x % 16];
	if (x >= 16)
	{
		print_hex(x / 16, cnt, hex);
		(*cnt)++;
	}
	write(1, &mod, 1);
}

int	ft_puthex_lower(va_list ap)
{
	int				cnt;
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	cnt = 1;
	print_hex(num, &cnt, "0123456789abcdef");
	return (cnt);
}

int	ft_puthex_upper(va_list ap)
{
	int				cnt;
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	cnt = 1;
	print_hex(num, &cnt, "0123456789ABCDEF");
	return (cnt);
}
