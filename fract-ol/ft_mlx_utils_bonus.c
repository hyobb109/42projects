/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:24:36 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/20 16:59:06 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	deal_key(int key, t_data *data)
{
	if (key == ESC)
		exit(EXIT_SUCCESS);
	else if (key == RIGHT)
		data->x_min *= 1.03;
	else if (key == LEFT)
		data->x_min *= 0.97;
	else if (key == UP)
		data->y_min *= 0.97;
	else if (key == DOWN)
		data->y_min *= 1.03;
	else if (key == R)
		init_data(data);
	return (0);
}

int	deal_mouse(int button, int x, int y, t_data *data)
{
	if (button == SCROLL_UP)
		data->boundary *= 0.9;
	else if (button == SCROLL_DOWN)
		data->boundary *= 1.1;
	else if (button == L_CLICK && x > 0 && y > 0)
		data->color = 0x000100;
	else if (button == R_CLICK && x > 0 && y > 0)
		data->color = 0x010100;
	return (0);
}

void	init_data(t_data *data)
{
	data->x_min = -3;
	data->y_min = -3;
	data->boundary = 6;
	data->color = 0x000005;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}
