/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:01:48 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/08 23:20:15 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_new_line(char *tmp_buff, ssize_t total)
{
	if (total > 0 && tmp_buff[total - 1] == '\n')
		return (1);
	return (0);
}

static ssize_t	find_new_line(t_info *data)
{
	ssize_t	len;
	ssize_t	idx;

	len = data->len;
	idx = data->idx;
	while (idx < data->rbyte)
	{
		len++;
		if (data->buffer[idx] == '\n')
			return (len);
		idx++;
	}
	return (len);
}

static int	init(char *tmp_buff, ssize_t *total)
{
	if (tmp_buff == NULL)
		return (0);
	*tmp_buff = '\0';
	*total = 0;
	return (1);
}

static char	*read_and_copy(int fd, char *tmp_buff, t_info *data, t_info **head)
{
	if (data->idx >= data->rbyte)
	{
		data->idx = 0;
		data->rbyte = read(fd, data->buffer, BUFFER_SIZE);
		if (data->rbyte < 0)
			return (free_res_gnl(tmp_buff, data, head));
	}
	data->len = find_new_line(data);
	tmp_buff = ft_strjoin_gnl(tmp_buff, data);
	return (tmp_buff);
}

char	*get_next_line(int fd)
{
	char			*tmp_buff;
	static t_info	*head;
	t_info			*data;

	data = find_data(&head, fd);
	if (data == NULL)
		return (0);
	tmp_buff = (char *)malloc(1);
	if (!init(tmp_buff, &data->total))
		return (0);
	while (data->rbyte)
	{
		tmp_buff = read_and_copy(fd, tmp_buff, data, &head);
		if (tmp_buff == NULL)
			return (0);
		if (is_new_line(tmp_buff, data->total))
			break ;
	}
	if (tmp_buff[0] == '\0')
		return (free_res_gnl(tmp_buff, data, &head));
	return (tmp_buff);
}
