# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:24:59 by hyobicho          #+#    #+#              #
#    Updated: 2023/03/03 18:50:20 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBFT_FLAG = -Llibft -lft
LIBFT_DIR = ./libft/
SRCS = \
ft_main.c
M_OBJ = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME)

# ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
# $(NAME): $(B_OBJ)
# 	$(CC) $(B_OBJ) $(MLX_FLAGS) $(CFLAGS) -o $(NAME)
# else
# $(NAME): $(M_OBJ)
# 	$(CC) $(M_OBJ) $(MLX_FLAGS) $(CFLAGS) -o $(NAME)
# endif

$(NAME): $(M_OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(M_OBJ) $(LIBFT_FLAG) $(CFLAGS) -o $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(M_OBJ)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean bonus