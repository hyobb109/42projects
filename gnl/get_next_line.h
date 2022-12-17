/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:26:38 by hyobicho          #+#    #+#             */
/*   Updated: 2022/12/17 20:11:29 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_info
{
	char	buffer[BUFFER_SIZE];
	ssize_t		idx;
	ssize_t		rbyte;
	ssize_t		len;
	ssize_t		total;
}	t_info;

void	*ft_memcpy(void *dst, const void *src, ssize_t n);
char	*ft_strjoin(char *s1, t_info *data);
char	*get_next_line(int fd);

#endif