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

static char	*free_res(char *tmp_buff, t_info *data)
{
	// data->buffer[0] = '\0';
	// data->idx = 0;
	// data->rbyte = -1;
	// data->len = 0;
	// data->total = 0;
	// data->fd = 0;
	// data->next = NULL;
	if (!data->pre && !data->next)
	{
		data->pre->next = data->next; 
		data->next->pre = data->pre;
	}
	free(data);
	// free(head);
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

t_info	*find_data(t_info *curr, int fd)
{
	t_info	*new;
	// fd 다르면 fd 같을때가지 or 마지막 노드까지 넘김
	// printf("next: %p\n", curr->next);
	while (curr->next && curr->fd != fd)
	{
		// printf("222check!\n");	
		curr = curr->next;
	}
	// fd값 같은지 체크 -> 같으면 현재 data 리턴
	if (fd == curr->fd)
	{
		// printf("111check!\n");	
		return(curr);
	}
	// printf("333check!\n");
	// 없으면 새로운 node 생성해서 초기화하고 연결 후 리턴
	new = (t_info *)malloc(sizeof(t_info));
	if (new == NULL)
		return (0);
	init_data(new, fd);
	new->pre = curr;
	// print_data(new);
	curr->next = new;
	return (new);
}

char	*get_next_line(int fd)
{
	char			*tmp_buff;
	static t_info	*head;
	t_info			*data;

	// 첫 노드면
	if (head == NULL)
	{
		head = malloc(sizeof(t_info));
		if (head == NULL)
			return (0);
		init_data(head, fd);
	}
	// data 가 가리키는 노드 정해주기 (fd 값 체크)
	data = find_data(head, fd);
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
				return (free_res(tmp_buff, data));
		}
		data->len = find_new_line(data);
		tmp_buff = ft_strjoin(tmp_buff, data);
		// print_data(data);
		// printf("**tmp: %s\n**", tmp_buff);
		if (tmp_buff == NULL)
			return (0);
		if (is_new_line(tmp_buff, data->total))
			break ;
	}
	if (tmp_buff[0] == '\0')
		return (free_res(tmp_buff, data));
	return (tmp_buff);
}

int main()
{
	int fd1 = open("./sample.txt", O_RDONLY);
	if (fd1 < 0)
		return 0;
	int fd2 = open("./test.txt", O_RDONLY);
	if (fd2 < 0)
		return 0;
	printf("===fd 1: %d===\n", fd1);
	for (int i = 0; i < 2; i++)
		printf("%s", get_next_line(fd1));
	printf("===fd 2: %d===\n", fd2);
	for (int i = 0; i < 2; i++)
		printf("%s", get_next_line(fd2));
	printf("===fd 1: %d===\n", fd1);
	for (int i = 0; i < 2; i++)
		printf("%s", get_next_line(fd1));
	printf("===fd 2: %d===\n", fd2);
	for (int i = 0; i < 2; i++)
		printf("%s", get_next_line(fd2));
	close(fd1);
	close(fd2);
	return 0;
}