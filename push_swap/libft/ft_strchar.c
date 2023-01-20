/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:21:15 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/19 17:47:19 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(va_list ap)
{
	unsigned char	ascii;

	ascii = va_arg(ap, unsigned int);
	write(1, &ascii, 1);
	return (1);
}

int	ft_putstr(va_list ap)
{
	int		len;
	char	*s;

	s = va_arg(ap, char *);
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
