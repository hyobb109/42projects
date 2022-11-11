/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:14:44 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/10 16:58:02 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
