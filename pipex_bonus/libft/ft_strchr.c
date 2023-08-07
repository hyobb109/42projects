/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:43:51 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/15 22:56:44 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	c1;

	c1 = (char)c;
	while (*s)
	{
		if (c1 == *s)
			return ((char *)s);
		s++;
	}
	if (c1 == '\0')
		return ((char *)s);
	return (0);
}
