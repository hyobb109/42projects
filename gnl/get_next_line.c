/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:01:48 by hyobicho          #+#    #+#             */
/*   Updated: 2022/12/09 09:48:49 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static void init_data(t_info *data, int fd)
// {
// 	(*data).idx = 0;
// 	(*data).rbyte = read(fd, (*data).buffer, BUFFER_SIZE);
// 	(*data).len = 0;
// }

char	*get_next_line(int fd)
{
	char			*res;
	static t_info	data = {"\0", 0, 1, 0, 0};

	res = malloc(1);
	if (res == NULL)
		return (0);
	*res = 0;
	data.total = 0;
	int cycle = 1;
	while (data.rbyte)
	{
		printf("#cycle %d\n", cycle);
		res = ft_strjoin(res, &data);
		data.rbyte = read(fd, data.buffer, BUFFER_SIZE);\
		if (data.rbyte < 0)
			return (0);
		while (data.buffer[data.len] != '\n' && data.len < data.rbyte)
		{
			data.len++;
			data.idx++;
		}
		if (data.buffer[data.len] == '\n')
		{
			data.len++;
			data.idx++;
		}
		printf("len: %d\n", data.len);
		printf("buff: %s\n", data.buffer);
		if (data.idx == data.rbyte)
			data.idx = 0;
		cycle++;
		printf("\n");
	}
	return (res);
}

int main() {
	int fd = open("sample.txt", O_RDONLY);
	if (fd < 0)
		return 1;
	for (int i = 1; i <= 5; i++)
	{
		printf("#call %d\n", i);
		printf("%s", get_next_line(fd));
	}
	close(fd);
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	return 0;
}