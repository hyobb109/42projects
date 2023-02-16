/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:40:58 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/17 01:23:40 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "./minilibx/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define N_MAX 128
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define R 15
# define L_CLICK 1
# define R_CLICK 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		type;
	int		color;
	double	x_min;
	double	y_max;
	double	boundary;
	double	a;
	double	b;
}	t_data;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mandelbrot(t_data *data);
void	julia(t_data *data);
int		get_depth(double x, double y, t_coord c);
int 	fractal_loop(t_data *data);
void	fractal_type(int argc, char **argv, t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
int		deal_mouse(int button, int x, int y, t_data *data);
int		deal_key(int button, t_data *data);
void	init_data(t_data *data);
void	ft_error(int code);

#endif