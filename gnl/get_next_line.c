/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:01:48 by hyobicho          #+#    #+#             */
/*   Updated: 2022/12/14 01:39:17 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_new_line(char *res, int i)
{
	if (i == 0 && res[i] == '\n')
		return (1);
	if (i > 0 && res[i - 1] == '\n')
		return (1);
	return (0);
}

static int	find_new_line(t_info data)
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

static char	*free_res(char *res)
{
	free(res);
	return (0);
}

static int	init(char *res, int *total)
{
	if (res == NULL)
		return (1);
	*res = '\0';
	*total = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	char			*res;
	static t_info	data = {"\0", 0, -1, 0, 0};

	res = (char *)malloc(1);
	if (init(res, &data.total))
		return (0);
	while (data.rbyte)
	{
		if (data.idx >= data.rbyte)
		{
			data.idx = 0;
			data.rbyte = read(fd, data.buffer, BUFFER_SIZE);
			if (data.rbyte < 0)
				return (free_res(res));
		}
		data.len = find_new_line(data);
		res = ft_strjoin(res, &data);
		if (res == NULL)
			return (0);
		if (is_new_line(res, data.total))
			break ;
	}
	if (res[0] == '\0')
		return (free_res(res));
	return (res);
}
