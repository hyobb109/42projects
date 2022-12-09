/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:01:48 by hyobicho          #+#    #+#             */
/*   Updated: 2022/12/09 05:42:52 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return 1;
	printf("fd: %d\n", fd);
	char buff[BUFFER_SIZE + 1];
	int size = read(fd, buff, BUFFER_SIZE);
	if (size < 0) {
		printf("error\n");
		return 1;
	}
	printf("%d bytes read\n", size);
	buff[size] = '\0';
	printf("%s\n", buff);
	for (int i = 0; i < size; i++)
		printf("buff[%d] = %d\n", i, buff[i]);
	close(fd);
	return 0;
}