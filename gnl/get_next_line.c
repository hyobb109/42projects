/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:01:48 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/08 22:10:50 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			return (free_res(tmp_buff, data, head));
	}
	data->len = find_new_line(data);
	tmp_buff = ft_strjoin(tmp_buff, data);
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
		return (free_res(tmp_buff, data, &head));
	return (tmp_buff);
}

// #include <fcntl.h>
// #include <limits.h>

// int main()
// {
// 	printf("%lu\n", SIZE_MAX);
//   	printf("The maximum value of ssize_t is %lld\n", (long long) SSIZE_MAX);
// 	int fd1 = open("./03.txt", O_RDONLY);
// 	int fd2 = open("./04.txt", O_RDONLY);
// 	int fd3 = open("./05.txt", O_RDONLY);
// 	char *s1 = get_next_line(fd1);
// 	char *s2 = get_next_line(fd2);
// 	char *s3 = get_next_line(fd3);
// 	printf("%s", s1);
// 	printf("%s", s2);
// 	printf("%s", s3);
// 	printf("%s", s1);
// 	printf("%s", s2);
// 	printf("%s", s3);
// 	printf("%s", s1);
// 	printf("%s", s2);
// 	printf("%s", s3);
// 	free(s1);
// 	free(s2);
// 	free(s3);
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return 0;
// }
