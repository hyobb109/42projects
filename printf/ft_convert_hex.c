/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:47:20 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/22 17:09:31 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprint.h"

static void	print_addr(unsigned long long x, size_t *cnt, const char *hex)
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

size_t	ft_putaddr(va_list ap)
{
	size_t				cnt;

	cnt = 3;
	write(1, "0x", 2);
	print_addr((unsigned long long)ap, &cnt, "0123456789abcdef");
	return (cnt);
}

static void	print_hex(unsigned int x, size_t *cnt, const char *hex)
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

size_t	ft_puthex_lower(va_list ap)
{
	size_t	cnt;

	cnt = 1;
	print_hex((unsigned int)ap, &cnt, "0123456789abcdef");
	return (cnt);
}

size_t	ft_puthex_upper(va_list ap)
{
	size_t	cnt;

	cnt = 1;
	print_hex((unsigned int)ap, &cnt, "0123456789ABCDEF");
	return (cnt);
}

#include <stdio.h>

int main()
{
	printf("d = %d\n", 010);
	ft_putnbr(010);
	printf("===============\n");
	ft_puthex_lower(-1);
	printf("\n");
	ft_puthex_upper(-1);
	printf("\n");
}
