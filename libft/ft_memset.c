/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:14:44 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/15 22:52:44 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	val;
	unsigned char	*s;
	size_t			i;

	val = (unsigned char)c;
	s = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*s++ = val;
		i++;
	}
	return (b);
}
