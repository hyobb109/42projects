/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:01:48 by hyobicho          #+#    #+#             */
/*   Updated: 2022/12/17 17:34:35 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_new_line(char *tmp_buff, ssize_t i)
{
	if (i == 0 && tmp_buff[i] == '\n')
		return (1);
	if (i > 0 && tmp_buff[i - 1] == '\n')
		return (1);
	return (0);
}

static ssize_t	find_new_line(t_info data)
{
	while (data.idx < data.rbyte)
	{
		data.len++;
		if (data.buffer[data.idx] == '\n')
			return (data.len);
		data.idx++;
	}
	return (data.len);
}

static char	*free_res(char *tmp_buff, t_info *data)
{
	data->buffer[0] = '\0';
	data->idx = 0;
	data->rbyte = -1;
	data->len = 0;
	data->total = 0;
	free(tmp_buff);
	return (0);
}

static int	init(char *tmp_buff, ssize_t *total)
{
	if (tmp_buff == NULL)
		return (0);
	*tmp_buff = '\0';
	*total = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	char			*tmp_buff;
	static t_info	data = {"\0", 0, -1, 0, 0};

	tmp_buff = (char *)malloc(1);
	if (!init(tmp_buff, &data.total))
		return (0);
	while (data.rbyte)
	{
		if (data.idx >= data.rbyte)
		{
			data.idx = 0;
			data.rbyte = read(fd, data.buffer, BUFFER_SIZE);
			if (data.rbyte < 0)
				return (free_res(tmp_buff, &data));
		}
		data.len = find_new_line(data);
		tmp_buff = ft_strjoin(tmp_buff, &data);
		if (tmp_buff == NULL)
			return (0);
		if (is_new_line(tmp_buff, data.total))
			break ;
	}
	if (tmp_buff[0] == '\0')
		return (free_res(tmp_buff, &data));
	return (tmp_buff);
}
