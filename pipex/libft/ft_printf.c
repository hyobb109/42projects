/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:07:00 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/19 17:43:01 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_func(int (*print[8])(va_list))
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

static int	idx(const char format, const char *set)
{
	int	i;

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
	int	(*print[8])(va_list);

	i = idx(format, set);
	if (i == -1)
		return (0);
	put_func(print);
	return (print[i](ap));
}

static int	check_format_len(va_list ap, const char format)
{
	if (format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (print_arg(format, ap, "csdiupxX"));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += check_format_len(ap, *format);
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
