/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:07:00 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/22 16:32:32 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprint.h"
#include <stdio.h> // TODO 지워라
// "cspdiuxX%"
static void	put_func(ssize_t (*print[])(va_list))
{
	(print)[0] = &ft_putchar;
	(print)[1] = &ft_putstr;
	(print)[2] = &ft_putnbr;
	(print)[3] = &ft_putnbr;
	(print)[5] = &ft_putaddr;
	(print)[6] = &ft_puthex_lower;
	(print)[7] = &ft_puthex_upper;
}

static ssize_t	find_type(va_list ap, const char format, const char *set)
{
	int		i;

	ssize_t (*print[9])(va_list);
	put_func(print);
	while (i < 8)
	{
		if (format == set[i])
			return (print[i](ap));
		i++;
	}
	if (format == set[i])
		return (print[0](ap));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	ssize_t	len;

	while (*format)
	{
		if (*format == '%')
		{
			printf("format : %s\n", format);
			va_start(ap, format);
			len += find_type(ap, *format, "csdiupxX\%");
			va_end(ap);
		}
		format++;
	}
	return (len);
}

int main()
{
	int a = 42;
	char b = a;
	char c[] = "hello";
	printf("printf: %% num %d, char %c, string %s\n", a, b, c);	
	ft_printf("ft_printf: %% num %d, char %c, string %s\n", a, b, c);	
}
