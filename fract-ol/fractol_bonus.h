/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:40:58 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/20 17:03:29 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "./minilibx/mlx.h"

# define WIDTH 800
# define HEIGHT 800
# define N_MAX 128
# define EXIT 17
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

typedef enum e_type
{
	WRONG_INPUT = 1,
	NO_INPUT,
	INVALID_NUMBER,
	MANDELBROT,
	JULIA,
	TROCORN,
	BURNINGSHIP
}	t_type;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		type;
	int		color;
	double	x_min;
	double	y_min;
	double	boundary;
	double	a;
	double	b;
}	t_data;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

int		ft_strcmp(const char *s1, const char *s2);
double	get_offset(char *str, int i, int sign, int p);

void	init_data(t_data *data);
int		fractal_loop_bonus(t_data *data);
void	mandelbrot(t_data *data);
void	julia(t_data *data);
void	tricorn(t_data *data);
void	burningship(t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		deal_mouse(int button, int x, int y, t_data *data);
int		deal_key(int key, t_data *data);

int		ft_exit(void);
void	ft_error_bonus(int code);

#endif