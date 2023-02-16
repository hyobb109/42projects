/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:40:52 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/17 07:39:39 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_error_bonus(int code)
{
	if (code == 1)
	{
		printf("Mandelbrot\n");
		printf("Julia\n");
		printf("Tricorn\n");
	}
	else if (code == 2)
		printf("You need to put two valid numbers for Julia set\n");
	else if (code == 3)
		printf("Invalid number!\n");
	exit(EXIT_FAILURE);
}

int	fractal_loop_bonus(t_data *data)
{
	if (data->type == 1)
		mandelbrot(data);
	else if (data->type == 2)
		julia(data);
	else if (data->type == 3)
		tricorn(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

static void	fractal_type_bonus(int argc, char **argv, t_data *data)
{
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			data->type = 1;
		else if (ft_strcmp(argv[1], "Julia") == 0)
		{
			if (argc != 4)
				ft_error_bonus(2);
			data->a = get_offset(argv[2], 0, 1, 1);
			data->b = get_offset(argv[3], 0, 1, 1);
			data->type = 2;
		}
		else if (ft_strcmp(argv[1], "Tricorn") == 0)
			data->type = 3;
		else
			ft_error_bonus(1);
		return ;
	}
	ft_error_bonus(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	fractal_type_bonus(argc, argv, &data);
	init_data(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fract-ol Bonus");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.len, &data.endian);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_mouse_hook(data.win, deal_mouse, &data);
	mlx_hook(data.win, EXIT, 0, ft_exit, &data);
	mlx_loop_hook(data.mlx, fractal_loop_bonus, &data);
	mlx_loop(data.mlx);
	return (0);
}
