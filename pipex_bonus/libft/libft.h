/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:52 by hyobicho          #+#    #+#             */
/*   Updated: 2023/03/03 20:48:35 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

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
char	*free_res_gnl(char *tmp_buff, t_info *data, t_info **head);
char	*ft_strjoin_gnl(char *s1, t_info *data);
char	*get_next_line(int fd);
void	free_strs(char **strs);

void	ft_error(char *message);
int		ft_printf(const char *format, ...);
int		ft_putchar(va_list ap);
int		ft_putstr(va_list ap);
int		ft_putnbr(va_list ap);
int		ft_putnbr_u(va_list ap);
int		ft_putaddr(va_list ap);
int		ft_puthex_lower(va_list ap);
int		ft_puthex_upper(va_list ap);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif