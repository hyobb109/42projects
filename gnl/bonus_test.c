#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

// void print_data(t_info *data)
// {
// 	printf("================\n");
// 	printf("buffer_idx: %zd\n", data->idx);
// 	printf("buffer: %s\n", data->buffer);
// 	printf("rbyte: %zd\n", data->rbyte);
// 	printf("len: %zd\n", data->len);
// 	printf("total: %zd\n", data->total);
// 	printf("fd: %d\n", data->fd);
// 	printf("================\n");
// }

void	*ft_memcpy(void *dst, const void *src, ssize_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	ssize_t				i;

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

static char	*read_and_copy(int fd, char *tmp_buff, t_info **data, t_info **head)
{
	if ((*data)->idx >= (*data)->rbyte)
	{
		(*data)->idx = 0;
		(*data)->rbyte = read(fd, (*data)->buffer, BUFFER_SIZE);
		if ((*data)->rbyte < 0)
			return (free_res(tmp_buff, *data, head));
	}
	(*data)->len = find_new_line(*data);
	tmp_buff = ft_strjoin(tmp_buff, *data);
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
		tmp_buff = read_and_copy(fd, tmp_buff, &data, &head);
		if (tmp_buff == NULL)
			return (0);
		if (is_new_line(tmp_buff, data->total))
			break ;
	}
	if (tmp_buff[0] == '\0')
		return (free_res(tmp_buff, data, &head));
	return (tmp_buff);
}

int main()
{
	int fd1 = open("./03.txt", O_RDONLY);
	int fd2 = open("./04.txt", O_RDONLY);
	int fd3 = open("./05.txt", O_RDONLY);
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
