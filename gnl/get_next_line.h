/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:26:38 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/08 21:52:21 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_info
{
	char			buffer[BUFFER_SIZE];
	ssize_t			idx;
	ssize_t			rbyte;
	ssize_t			len;
	ssize_t			total;
	int				fd;
	struct s_info	*pre;
	struct s_info	*next;
}	t_info;

void	init_data(t_info *data, int fd);
t_info	*find_data(t_info **head, int fd);
void	*ft_memcpy(void *dst, const void *src, ssize_t n);
char	*free_res(char *tmp_buff, t_info *data, t_info **head);
char	*ft_strjoin(char *s1, t_info *data);
char	*get_next_line(int fd);

#endif