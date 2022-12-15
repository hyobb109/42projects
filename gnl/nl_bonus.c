#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

void	*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	int				i;

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

static int	is_new_line(char *tmp_buff, int i)
{
	if (i == 0 && tmp_buff[i] == '\n')
		return (1);
	if (i > 0 && tmp_buff[i - 1] == '\n')
		return (1);
	return (0);
}

static int	find_new_line(t_info *data)
{
	while (data->idx < data->rbyte)
	{
		data->len++;
		if (data->buffer[data->idx] == '\n')
			return (data->len);
		data->idx++;
	}
	return (data->len);
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

static int	init(char *tmp_buff, int *total)
{
	if (tmp_buff == NULL)
		return (0);
	*tmp_buff = '\0';
	*total = 0;
	return (1);
}

t_info	*find_data(t_info *lst, int fd)
{
	t_info	*curr;
	// fd값 같은지 체크 -> 같으면 현재 data 리턴
	// fd 다르면 새로운 node 생성해서 초기화하고 리턴
}

char	*get_next_line(int fd)
{
	char			*tmp_buff;
	static t_info	*head;
	t_info			*data;

	// data 가 가리키는 노드 정해주기 (fd 값 체크)
	data = find_data(head, fd);
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
				return (free_res(tmp_buff, &data));
		}
		data->len = find_new_line(data);
		tmp_buff = ft_strjoin(tmp_buff, &data);
		if (tmp_buff == NULL)
			return (0);
		if (is_new_line(tmp_buff, data->total))
			break ;
	}
	if (tmp_buff[0] == '\0')
		return (free_res(tmp_buff, &data));
	return (tmp_buff);
}

int main()
{
	int fd1 = open("./sample->txt", O_RDONLY);
	if (fd1 < 0)
		return 0;
	int fd2 = open("./test->txt", O_RDONLY);
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