/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:34:54 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/17 07:37:04 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_depth(double x, double y, double a, double b)
{
	int		n;
	t_coord	new;

	n = 0;
	while (n < N_MAX)
	{
		new.x = pow(x, 2) - pow(y, 2) + a;
		new.y = 2 * x * y + b;
		if (pow(new.x, 2) + pow(new.y, 2) > 4)
			return (n);
		x = new.x;
		y = new.y;
		n++;
	}
	return (n);
}

void	mandelbrot(t_data *data)
{
	t_coord	new;
	int		x;
	int		y;
	int		n;

	x = 0;
	while (x < WIDTH)
	{
		new.x = data->x_min + (data->boundary / WIDTH) * x;
		y = 0;
		while (y < HEIGHT)
		{
			new.y = data->y_max - (data->boundary / HEIGHT) * y;
			n = get_depth(new.x, new.y, new.x, new.y);
			if (n == N_MAX)
				my_mlx_pixel_put(data, x, y, 0x000000);
			else
				my_mlx_pixel_put(data, x, y, 0xffffff - data->color * n);
			y++;
		}
		x++;
	}
}

void	julia(t_data *data)
{
	t_coord	new;
	int		x;
	int		y;
	int		n;

	x = 0;
	while (x < WIDTH)
	{
		new.x = data->x_min + (data->boundary / WIDTH) * x;
		y = 0;
		while (y < HEIGHT)
		{
			new.y = data->y_max - (data->boundary / HEIGHT) * y;
			n = get_depth(new.x, new.y, data->a, data->b);
			if (n == N_MAX)
				my_mlx_pixel_put(data, x, y, 0x000000);
			else
				my_mlx_pixel_put(data, x, y, 0xffffff - data->color * n);
			y++;
		}
		x++;
	}
}

int	fractal_loop(t_data *data)
{
	if (data->type == 1)
		mandelbrot(data);
	else if (data->type == 2)
		julia(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
