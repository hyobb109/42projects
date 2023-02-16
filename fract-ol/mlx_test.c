/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:40:52 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/16 20:34:29 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key(int button, t_data *data)
{
	// if key가 esc면 window 닫음
	if (button == ESC)
		exit(0);
	else if (button == LEFT)
	{
		
	}
	// 방향 이동..
	return (0);
}

// int	deal_mouse(int button, int x, int y, t_data *data)
int	deal_mouse(int button, int x, int y, t_data *data)
{
	// 확대 -> 경계값 작아짐, 축소 -> 경계값 커짐  ==> 적용이 안 됨..
	if (button == SCROLL_UP)
	{
		// 배율.. 어떻게..??
		data->boundary *= 0.9;
		printf("(%d, %d)\n", x, y);
		printf("boundary: %f\n", data->boundary);
	}
	else if (button == SCROLL_DOWN)
	{
		data->boundary += data->boundary * 0.05;
		printf("(%d, %d)\n", x, y);
		printf("boundary: %f\n", data->boundary);
	}
	else if (button == L_CLICK)
	{
		if ((10 <= x && x <= 20) && (-15 <= y && y <= -5))
		{

			exit(0);
		}
	}
	return (0);
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

void	mandelbrot(t_data *data)
{
	t_coord c;
	int		x;
	int		y;
	int 	n;

	x = 0;
	while (x < WIDTH)
	{
		c.x = - data->boundary + (data->boundary * 2 / WIDTH) * x;
		y = 0;
		while (y < HEIGHT)
		{
			c.y =  data->boundary - (data->boundary * 2 / HEIGHT) * y;
			n = get_depth(c.x, c.y, c);
			// if (n)
			// 	printf("(%d, %d) => (%f, %f), n: %d\n", x, y, c.x, c.y, n);
			if (n == N_MAX)
				my_mlx_pixel_put(data, x, y, 0x000000 * n);
			else
				my_mlx_pixel_put(data, x, y, 0xffffff - 0x040300 * n);
			y++;
		}
		x++;
	}
}

void	julia(t_data *data)
{
	t_coord c;
	int		x;
	int		y;
	int 	n;

	x = 0;
	while (x < WIDTH)
	{
		c.x = - data->boundary + (data->boundary * 2 / WIDTH) * x;
		y = 0;
		while (y < HEIGHT)
		{
			c.y =  data->boundary - (data->boundary * 2 / HEIGHT) * y;
			n = get_depth(c.x, c.y, c);
			// if (n)
			// 	printf("(%d, %d) => (%f, %f), n: %d\n", x, y, c.x, c.y, n);
			my_mlx_pixel_put(data, x, y, 0xffffff - 0x000507 * n);
			y++;
		}
		x++;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	fractal_type(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			return (1);
		if (ft_strcmp(argv[1], "Julia") == 0)
			return (2);
	}	
	printf("Mandelbrot\n");
	printf("Julia\n");
	exit(EXIT_FAILURE);
}

int fractal_loop(t_data *data)
{
	if (data->type == 1)
		mandelbrot(data);
	// else if (data.type == 2)
	// 	julia(&data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;

	data.boundary = 2;
	// check para
	data.type = fractal_type(argc, argv);
	// set up the connection to the display
	// non-null pointer is returned as a connection identifier
	data.mlx = mlx_init();
	// manage windows
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "my fract-ol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_mouse_hook(data.win, deal_mouse, &data);
	mlx_loop_hook(data.mlx, fractal_loop, &data);
	// handle keyboard or mouse events
	// infinite loop that waits for an event
	mlx_loop(data.mlx);
	return (0);
}