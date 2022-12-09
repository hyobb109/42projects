/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:26:18 by hyobicho          #+#    #+#             */
/*   Updated: 2022/12/09 09:48:49 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == 0)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (dst);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *old, t_info *data)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (data->total + data->len + 1));
	if (new == NULL)
		return (0);
	if (data->total != 0)
	{
		ft_memcpy(new, old, data->total);
		printf("moved old: %s\n", new);
	}
	free(old);
	ft_memcpy(new + data->total, data->buffer + data->idx, data->len);
	data->total += data->len;
	new[data->total] = 0;
	printf("old + new: %s\n", new);


	/* if (data->total != 0)
	{
		printf("old: %s\n", old);
		while (old[i])
		{
			new[i] = old[i];
			i++;
		}
		free(old);
	}
	data->total += data->len;
	printf("total: %d\n", data->total);
	// printf("data->idx: %d\n", data->idx);
	while (data->idx < data->len)
	{
		printf("data->idx: %d\n", data->idx);
		new[i++] = data->buffer[data->idx];
		data->idx++;
	} */
	//new[data->idx] = '\0';
	// printf("===new===\n");
	
	data->len = 0;
	return (new);
}
