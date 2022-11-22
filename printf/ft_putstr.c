/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:14:55 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/22 16:24:44 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprint.h"

size_t	ft_putstr(va_list ap)
{
	size_t	len;
	char	*s;

	s = (char *)ap;
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
