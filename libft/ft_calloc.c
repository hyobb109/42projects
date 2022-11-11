/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:21:35 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/10 16:54:08 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t				total;
	unsigned char		*res;

	total = count * size;
	if (count != 0 && total / count != size)
		return (0);
	res = (unsigned char *)malloc(total);
	if (res == NULL)
		return (0);
	return (ft_memset(res, 0, total));
}
