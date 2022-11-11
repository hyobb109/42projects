/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:02:31 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/09 21:02:26 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	size_t	len;

	c1 = (char)c;
	len = ft_strlen(s);
	while (*s)
		s++;
	if (c1 == '\0')
		return ((char *)s);
	while (len-- > 0)
	{
		s--;
		if (c1 == *s)
			return ((char *)s);
	}
	return (0);
}
