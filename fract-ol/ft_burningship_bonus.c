/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:46:15 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/20 16:49:15 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	get_depth_bs(double x, double y, double a, double b)
{
	int		n;
	t_coord	new;

	n = 0;
	while (n < N_MAX)
	{
		new.x = pow(x, 2) - pow(y, 2) + a;
		new.y = fabs(2 * x * y) + b;
		if (pow(new.x, 2) + pow(new.y, 2) > 4)
			return (n);
		x = new.x;
		y = new.y;
		n++;
	}
	return (n);
}

void	burningship(t_data *data)
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
			new.y = data->y_min + (data->boundary / HEIGHT) * y;
			n = get_depth_bs(new.x, new.y, new.x, new.y);
			if (n == N_MAX)
				my_mlx_pixel_put(data, x, y, 0x000000);
			else
				my_mlx_pixel_put(data, x, y, 0xffffff - data->color * n);
			y++;
		}
		x++;
	}
}
