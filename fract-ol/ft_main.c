/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:40:52 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/20 17:01:11 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_type(int argc, char **argv, t_data *data)
{
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			data->type = MANDELBROT;
		else if (ft_strcmp(argv[1], "Julia") == 0)
		{
			if (argc != 4)
				ft_error(NO_INPUT);
			data->a = get_offset(argv[2], 0, 1, 1);
			data->b = get_offset(argv[3], 0, 1, 1);
			data->type = JULIA;
		}
		else
			ft_error(WRONG_INPUT);
		return ;
	}
	ft_error(WRONG_INPUT);
}

int	main(int argc, char **argv)
{
	t_data	data;

	fractal_type(argc, argv, &data);
	init_data(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Hyobicho's Fract-ol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.len, &data.endian);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_mouse_hook(data.win, deal_mouse, &data);
	mlx_hook(data.win, EXIT, 0, ft_exit, &data);
	mlx_loop_hook(data.mlx, fractal_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
