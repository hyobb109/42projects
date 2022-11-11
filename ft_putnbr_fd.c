/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:24:50 by hyobicho          #+#    #+#             */
/*   Updated: 2022/11/10 23:39:15 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(long long num, int fd)
{
	long long	mod;

	mod = num % 10 + '0';
	if (num >= 10)
		print(num / 10, fd);
	write(fd, &mod, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	print(num, fd);
}
