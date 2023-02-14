/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:40:52 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/14 22:12:02 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key()
{
	// if key가 esc면 프로그램 종료
	exit(EXIT_SUCCESS);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_depth(double x, double y, t_coord c)
{
	int	n;
	double	nx;
	double	ny;

	n = 0;
	while (n < N_MAX)
	{
		nx = pow(x, 2) - pow(y, 2) + c.x;
		ny = 2 * x * y + c.y;
		if (pow(nx, 2) + pow(ny, 2) > 4)
			return (n);
		x = nx;
		y = ny;
		n++;
	}
	return (n);
}

// void	get_coord(int h, int w, t_coord *c)
// {
// 	c->x = w + (4.0 / WIDTH) * w - 2.0; 
// 	c->y = h + (4.0 / HEIGHT) * h - 2.0; 
// }

void	mandelbrot(t_data *data)
{
	t_coord c;
	int		x;
	int		y;
	int 	n;

	x = 0;
	while (x < HEIGHT)
	{
		c.x = - 2 + (4.0 / HEIGHT) * x;
		y = 0;
		while (y < WIDTH)
		{
			c.y =  2 - (4.0 / WIDTH) * y;
			n = get_depth(c.x, c.y, c);
			// if (n)
				// printf("(%d, %d) => (%f, %f), n: %d\n", x, y, c.x, c.y, n);
			// if (n < 30)
			// 	my_mlx_pixel_put(data, x, y, 0x606060);
			// else if (n < 60)
			// 	my_mlx_pixel_put(data, x, y, 0xccffff);
			// else if (n < 100)
			// 	my_mlx_pixel_put(data, x, y, 0x99cfee);
			// else
				my_mlx_pixel_put(data, x, y, 1343 * n);
			y++;
		}
		x++;
	}
}

// void terminate()
// {
// 	exit()
// }

int main()
{
	t_vars ptr;
	t_data	img;

	// set up the connection to the display
	// non-null pointer is returned as a connection identifier
	ptr.mlx = mlx_init();
	// manage windows
	ptr.win = mlx_new_window(ptr.mlx, WIDTH, HEIGHT, "my fract-ol");
	img.img = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mandelbrot(&img);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
	// mlx_key_hook(ptr.win, deal_key, &ptr);
	// mlx_mouse_hook(ptr.win, terminate, &ptr);
	// handle keyboard or mouse events
	// infinite loop that waits for an event
	mlx_loop(ptr.mlx);
	return (0);
}