/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:34:09 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/23 19:44:13 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <errno.h>

size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
int		ft_putchar(va_list ap);
int		ft_putstr(va_list ap);
int		ft_putnbr(va_list ap);
int		ft_putnbr_u(va_list ap);
int		ft_putaddr(va_list ap);
int		ft_puthex_lower(va_list ap);
int		ft_puthex_upper(va_list ap);

#endif