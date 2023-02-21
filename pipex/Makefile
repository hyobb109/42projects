# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:24:59 by hyobicho          #+#    #+#              #
#    Updated: 2023/02/21 15:48:44 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
B_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror# -g -fsanitize=address
LIBFT_FLAG = -Llibft -lft
SRCS = \
ft_main.c
#test_utils.c
M_OBJ = $(SRCS:.c=.o)
LIBFT_DIR = ./libft/

all: $(NAME)

$(NAME): $(M_OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(M_OBJ) $(LIBFT_FLAG) $(CFLAGS) -o $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(M_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean