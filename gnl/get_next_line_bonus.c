/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:02:17 by hyobicho          #+#    #+#             */
/*   Updated: 2022/12/19 22:11:21 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	is_new_line(char *tmp_buff, ssize_t i)
{
	if (i == 0 && tmp_buff[i] == '\n')
		return (1);
	if (i > 0 && tmp_buff[i - 1] == '\n')
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

static char	*free_res(char *tmp_buff, t_info *data, t_info **head)
{
	if (data->pre && data->next)
	{
		data->pre->next = data->next; 
		data->next->pre = data->pre;
	}
	else if (data->pre)
		data->pre->next = NULL;
	else if (data->next)
		data->next->pre = NULL;
	else
		*head = NULL;
	free(data);
	data = NULL;
	free(tmp_buff);
	tmp_buff = 0;
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
		return(curr);
	new = (t_info *)malloc(sizeof(t_info));
	if (new == NULL)
		return (0);
	init_data(new, fd);
	curr->next = new;
	new->pre = curr;
	return (new);
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
		if (data->idx >= data->rbyte)
		{
			data->idx = 0;
			data->rbyte = read(fd, data->buffer, BUFFER_SIZE);
			if (data->rbyte < 0)
				return (free_res(tmp_buff, data, &head));
		}
		data->len = find_new_line(data);
		tmp_buff = ft_strjoin(tmp_buff, data);
		if (tmp_buff == NULL)
			return (0);
		if (is_new_line(tmp_buff, data->total))
			break ;
	}
	if (tmp_buff[0] == '\0')
		return (free_res(tmp_buff, data, &head));
	return (tmp_buff);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
// 	int fd1 = open("./03.txt", O_RDONLY);
// 	// int fd2 = open("./04.txt", O_RDONLY);
// 	// int fd3 = open("./05.txt", O_RDONLY);
// 	printf("===fd 1: %d===\n", fd1);
// 	for (int i = 0; i < 1; i++)
// 		printf("%s", get_next_line(fd1));
// 	// printf("===fd 2: %d===\n", fd2);
// 	// for (int i = 0; i < 2; i++)
// 	// 	printf("%s", get_next_line(fd2));
// 	// printf("===fd 3: %d===\n", fd3);
// 	// for (int i = 0; i < 2; i++)
// 	// 	printf("%s", get_next_line(fd3));
// 	// printf("===fd 1: %d===\n", fd1);
// 	// for (int i = 0; i < 2; i++)
// 	// 	printf("%s", get_next_line(fd1));
// 	// printf("===fd 3: %d===\n", fd3);
// 	// for (int i = 0; i < 2; i++)
// 	// 	printf("%s", get_next_line(fd3));
// 	// printf("===fd 2: %d===\n", fd2);
// 	// for (int i = 0; i < 2; i++)
// 	// 	printf("%s", get_next_line(fd2));
// 	close(fd1);
// 	// close(fd2);
// 	// close(fd3);
// 	return 0;
// }
