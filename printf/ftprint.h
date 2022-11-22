/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:34:09 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/22 16:08:41 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINT_H
# define FTPRINT_H

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_putchar(va_list ap);
size_t	ft_putnbr(va_list ap);
size_t	ft_putunbr(va_list ap);
size_t	ft_putstr(va_list ap);
size_t	ft_putaddr(va_list ap);
size_t	ft_puthex_lower(va_list ap);
size_t	ft_puthex_upper(va_list ap);

#endif