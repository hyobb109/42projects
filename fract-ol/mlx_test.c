/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:40:52 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/17 06:20:01 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key(int key, t_data *data)
{
	// if key가 esc면 window 닫음
	if (key == ESC)
		exit(EXIT_SUCCESS);
	else if (key == RIGHT)
	{
		//printf("data->x_min = %f\n", data->x_min);
		data->x_min *= 1.03;
	}
	else if (key == LEFT)
	{
		//printf("data->x_min = %f\n", data->x_min);
		data->x_min *= 0.97;
	}
	else if (key == UP)
	{
		//printf("data->y_max = %f\n", data->y_max);
		data->y_max *= 0.97;
	}
	else if (key == DOWN)
	{
		//printf("data->y_max = %f\n", data->y_max);
		data->y_max *= 1.03;
	}
	else if (key == R)
	{
		init_data(data);
	}
	return (0);
}

int	deal_mouse(int button, int x, int y, t_data *data)
{
	// 확대 -> 경계값 작아짐, 축소 -> 경계값 커짐
	if (button == SCROLL_UP)
	{
		//printf("boundary: %f\n", data->boundary);
		data->boundary *= 0.9;
	}
	else if (button == SCROLL_DOWN)
	{
		//printf("boundary: %f\n", data->boundary);
		data->boundary *= 1.1;
	}
	else if (button == L_CLICK && x > 0 && y > 0)
	{
		// printf("(%d, %d)\n", x, y);
		data->color = 0x000100;
	}
	else if (button == R_CLICK && x > 0 && y > 0)
	{
		data->color = 0x010100;
	}
	return (0);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

int	get_depth_t(double x, double y, double a, double b)
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
		y = -new.y;
		n++;
	}
	return (n);
}

void	tricorn(t_data *data)
{
	t_coord new;
	int		x;
	int		y;
	int 	n;

	x = 0;
	while (x < WIDTH)
	{
		new.x = data->x_min + (data->boundary / WIDTH) * x;
		y = 0;
		while (y < HEIGHT)
		{
			new.y = data->y_max - (data->boundary / HEIGHT) * y;
			n = get_depth_t(new.x, -new.y, new.x, new.y);
			// if (n)
			// 	printf("(%d, %d) => (%f, %f), n: %d\n", x, y, new.x, new.y, n);
			if (n == N_MAX)
				my_mlx_pixel_put(data, x, y, 0x000000);
			else
				my_mlx_pixel_put(data, x, y, 0xffffff - data->color * n);
				// my_mlx_pixel_put(data, x, y, 0x000000 + data->color * n);
			y++;
		}
		x++;
	}
}

void	mandelbrot(t_data *data)
{
	t_coord new;
	int		x;
	int		y;
	int 	n;

	x = 0;
	while (x < WIDTH)
	{
		new.x = data->x_min + (data->boundary / WIDTH) * x;
		y = 0;
		while (y < HEIGHT)
		{
			new.y = data->y_max - (data->boundary / HEIGHT) * y;
			n = get_depth(new.x, new.y, new.x, new.y);
			// if (n)
			// 	printf("(%d, %d) => (%f, %f), n: %d\n", x, y, new.x, new.y, n);
			if (n == N_MAX)
				my_mlx_pixel_put(data, x, y, 0x000000);
			else
				my_mlx_pixel_put(data, x, y, 0xffffff - data->color * n);
				// my_mlx_pixel_put(data, x, y, 0x000000 + data->color * n);
			y++;
		}
		x++;
	}
}

void	julia(t_data *data)
{
	t_coord new;
	int		x;
	int		y;
	int 	n;

	x = 0;
	while (x < WIDTH)
	{
		new.x = data->x_min + (data->boundary / WIDTH) * x;
		y = 0;
		while (y < HEIGHT)
		{
			new.y = data->y_max - (data->boundary / HEIGHT) * y;
			n = get_depth(new.x, new.y, data->a, data->b);
			// if (n)
			// 	printf("(%d, %d) => (%f, %f), n: %d\n", x, y, new.x, new.y, n);
			if (n == N_MAX)
				my_mlx_pixel_put(data, x, y, 0x000000);
			else
				my_mlx_pixel_put(data, x, y, 0xffffff - data->color * n);
				// my_mlx_pixel_put(data, x, y, 0x000000 + data->color * n);
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char a)
{
	if ((a >= 9 && a <= 13) || a == 32)
		return (1);
	return (0);
}

double	get_offset(char *str)
{
	t_coord	num;
	double	res;
	int		i;
	int		sign;
	int		n;

	i = 0;
	sign = 1;
	num.x = 0;
	num.y = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
	{
		num.x = num.x * 10 + str[i++] - '0';
	}
	n = 1;
	if (str[i] == '.')
	{
		while (ft_isdigit(str[++i]))
		{
			num.y += (str[i] - '0') / pow(10, n++);
		}
	}
	if (str[i])
		ft_error(3);
	res = num.x + num.y;
	return (sign * res);
}

void	ft_error(int code)
{
	if (code == 1)
	{
		printf("Mandelbrot\n");
		printf("Julia\n");
		// bonus
		printf("Tricorn\n");
	}
	else if (code == 2)
	{
		printf("You need to put two valid numbers for Julia set\n");
	}
	else if (code == 3)
	{
		printf("Invalid number!\n");
	}
	exit(EXIT_FAILURE);
}

void	fractal_type(int argc, char **argv, t_data *data)
{
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			data->type = 1;
		else if (ft_strcmp(argv[1], "Julia") == 0)
		{
			if (argc != 4)
				ft_error(2);
			data->a = get_offset(argv[2]);
			data->b = get_offset(argv[3]);
			data->type = 2;
		}
		else if (ft_strcmp(argv[1], "Tricorn") == 0)
			data->type = 3;
		else
			ft_error(1);
		return ;
	}
	ft_error(1);
}

int fractal_loop(t_data *data)
{
	if (data->type == 1)
		mandelbrot(data);
	else if (data->type == 2)
		julia(data);
	// bonus
	else if (data->type == 3)
		tricorn(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	init_data(t_data *data)
{
	data->x_min = -2.5;
	data->y_max = 2.5;
	data->boundary = 5;
	data->color = 0x000005;
}

int	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_data	data;
	//init data
	fractal_type(argc, argv, &data);
	// printf("c.x: %f, x.y: %f\n", c.x, c.y);
	init_data(&data);
	// set up the connection to the display
	// non-null pointer is returned as a connection identifier
	data.mlx = mlx_init();
	// manage windows
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "my fract-ol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_mouse_hook(data.win, deal_mouse, &data);
	mlx_hook(data.win, EXIT, 0, ft_exit, &data);
	mlx_loop_hook(data.mlx, fractal_loop, &data);
	// handle keyboard or mouse events
	// infinite loop that waits for an event
	mlx_loop(data.mlx);
	return (0);
}