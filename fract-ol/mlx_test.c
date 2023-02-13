/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:40:52 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/13 22:13:27 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key(void)
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

int	get_depth(double x, double y)
{
	int	n;
	double	nx;
	double	ny;

	n = 0;
	while (n <= MAX_N)
	{
		nx = pow(x, 2) + pow(y, 2) + x;
		ny = 2 * x * y + y;
		if (pow(nx, 2) + pow(ny, 2) > 4)
			return (n);
		x = nx;
		y = ny;
		n++;
	}
	return (n);
}

void	mandelbrot(t_data *data)
{
	int	a;
	int	b;
	int n;

	a = 0;
	while (a < WIDTH)
	{
		b = 0;
		while (b < HEIGHT)
		{
			// 좌표 변환...
			get_coord();
			n = get_depth((double)a, (double)b);
			if (n < 30)
				my_mlx_pixel_put(data, a, b, 0x000000);
			else if (n < 60)
				my_mlx_pixel_put(data, a, b, 0xccffff);
			else if (n < 100)
				my_mlx_pixel_put(data, a, b, 0x99cfee);
			else
				my_mlx_pixel_put(data, a, b, 0xffffff);
			b++;
		}
		a++;
	}
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	// set up the connection to the display
	// non-null pointer is returned as a connection identifier
	mlx_ptr = mlx_init();
	// manage windows
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "test");
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mandelbrot(&img);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_key_hook(win_ptr, deal_key, 0);
	// handle keyboard or mouse events
	// infinite loop that waits for an event
	mlx_loop(mlx_ptr);
	return (0);
}