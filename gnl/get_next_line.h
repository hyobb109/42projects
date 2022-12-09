/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:26:38 by hyobicho          #+#    #+#             */
/*   Updated: 2022/12/09 09:33:15 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> // 지우기
#include <stdio.h> // 지우기

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

typedef struct s_info 
{
	char buffer[BUFFER_SIZE];
	int	idx;
	int	rbyte;
	int len; // 새로 read() 후, result에 추가할 문자배열 길이를 저장, join()에서 사용
	int	total; // 현재 res의 문자 길이
	// struct s_info *next; // 다음 fd 주소 가지고 있음(bonus)
}	t_info;

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char *s1, t_info *data);
char	*get_next_line(int fd);

#endif