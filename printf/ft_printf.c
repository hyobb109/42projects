/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:07:00 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/23 19:52:36 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_func(int (*print[8])(va_list))
{
	(print)[0] = &ft_putchar;
	(print)[1] = &ft_putstr;
	(print)[2] = &ft_putnbr;
	(print)[3] = &ft_putnbr;
	(print)[4] = &ft_putnbr_u;
	(print)[5] = &ft_putaddr;
	(print)[6] = &ft_puthex_lower;
	(print)[7] = &ft_puthex_upper;
}

static int idx(const char format, const char *set)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (format == set[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	print_arg(const char format, va_list ap, const char *set)
{
	int	i;
	int	res;
	int (*print[8])(va_list);

	i = idx(format, set);
	if (i == -1)
		return (-1);
	put_func(print);
	return (print[i](ap));
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		va_len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*++format == '%')
			{
				write(1, "%", 1);
				len += 1;
			}
			else
			{
				va_len = print_arg(*format, ap, "csdiupxX");
				if (va_len < 0)
					return (va_len);
				len += va_len;
			}
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}

// int main()
// {
// 	char str[] = "hello";
// 	int res = printf("percent: %%, char: %c, string: %s, int: %d, i: %i, u_int: %u, addr: %p, hex: %x, HEX: %X\n", 'z', str, -42, -42, -42, str, 42, 42);
// 	int res1 = ft_printf("percent: %%, char: %c, string: %s, int: %d, i: %i, u_int: %u, addr: %p, hex: %x, HEX: %X\n", 'z', str, -42, -42, -42, str, 42, 42);
// 	printf("\nres: %d, res1: %d\n", res, res1);
// 	return 0;
// }