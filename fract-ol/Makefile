# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:24:59 by hyobicho          #+#    #+#              #
#    Updated: 2023/02/17 07:50:53 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
MLX_FLAGS = -Lminilibx -lmlx -framework OpenGL -framework Appkit
SRCS = \
ft_main.c \
ft_check_para.c \
ft_mlx_utils.c  \
ft_fractal.c 
B_SRCS = \
ft_main_bonus.c \
ft_check_para_bonus.c \
ft_mlx_utils.c \
ft_fractal_bonus.c
M_OBJ = $(SRCS:.c=.o)
B_OBJ = $(B_SRCS:.c=.o)
MLX_DIR = ./minilibx/

all: $(NAME)

bonus: $(NAME)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(B_OBJ)
	$(CC) $(B_OBJ) $(MLX_FLAGS) $(CFLAGS) -o $(NAME)
else
$(NAME): $(M_OBJ)
	$(CC) $(M_OBJ) $(MLX_FLAGS) $(CFLAGS) -o $(NAME)
endif

%.o : %.c
	$(CC) -c $(CFLAGS) -I$(MLX_DIR) -O3 $< -o $@

clean:
	rm -f $(M_OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean bonus