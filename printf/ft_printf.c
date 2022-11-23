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

static int	find_type(va_list ap, const char format, const char *set)
{
	int		i;
	int		(*print[8])(va_list);

	if (format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	put_func(print);
	i = 0;
	while (i < 8)
	{
		if (format == set[i])
			return (print[i](ap));
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = ft_strlen(format);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			len -= 2;
			format++;
			len += find_type(ap, *format, "csdiupxX");
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (len);
}
