/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:26:18 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/08 22:21:52 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	init_data(t_info *data, int fd)
{
	data->buffer[0] = '\0';
	data->idx = 0;
	data->rbyte = -1;
	data->len = 0;
	data->total = 0;
	data->fd = fd;
	data->pre = NULL;
	data->next = NULL;
}

t_info	*find_data(t_info **head, int fd)
{
	t_info	*new;
	t_info	*curr;

	if (*head == NULL)
	{
		*head = malloc(sizeof(t_info));
		if (*head == NULL)
			return (0);
		init_data(*head, fd);
	}
	curr = *head;
	while (curr->next && curr->fd != fd)
		curr = curr->next;
	if (fd == curr->fd)
		return (curr);
	new = (t_info *)malloc(sizeof(t_info));
	if (new == NULL)
		return (0);
	init_data(new, fd);
	curr->next = new;
	new->pre = curr;
	return (new);
}

char	*free_res(char *tmp_buff, t_info *data, t_info **head)
{
	if (data->pre && data->next)
	{
		data->pre->next = data->next;
		data->next->pre = data->pre;
	}
	else if (data->pre)
		data->pre->next = NULL;
	else if (data->next)
	{
		data->next->pre = NULL;
		*head = data->next;
	}
	else
		*head = NULL;
	free(data);
	data = NULL;
	free(tmp_buff);
	tmp_buff = 0;
	return (0);
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
		ft_memcpy(new, old, data->total);
	free(old);
	ft_memcpy(new + data->total, data->buffer + data->idx, data->len);
	data->total += data->len;
	new[data->total] = '\0';
	data->idx += data->len;
	data->len = 0;
	return (new);
}
