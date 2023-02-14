/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:40:58 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/14 21:07:45 by hyobicho         ###   ########.fr       */
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
# define X_MAX 2
# define Y_MAX 2
# define X_MIN -2
# define Y_MIN -2

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

#endif