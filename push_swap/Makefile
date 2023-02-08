# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:24:59 by hyobicho          #+#    #+#              #
#    Updated: 2023/02/09 03:56:19 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror# -g -fsanitize=address
LIBFT_FLAG = -Llibft -lft
SRCS = \
ft_main.c \
ft_lst_utils.c \
ft_lst_check.c \
ft_cmd_swap.c \
ft_cmd_push.c \
ft_cmd_rotate.c \
ft_cmd_reverse.c \
ft_sort_small.c \
ft_sort_big.c \
#test_utils.c
B_SRCS = \
ft_checker.c \
ft_lst_utils.c \
ft_lst_check.c \
ft_cmd_swap.c \
ft_cmd_push.c \
ft_cmd_rotate.c \
ft_cmd_reverse.c \
#test_utils.c
M_OBJ = $(SRCS:.c=.o)
B_OBJ = $(B_SRCS:.c=.o)
LIBFT_DIR = ./libft/

all: $(NAME)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(B_OBJ) $(LIBFT_FLAG) $(CFLAGS) -o $(B_NAME)

$(NAME): $(M_OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(M_OBJ) $(LIBFT_FLAG) $(CFLAGS) -o $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(M_OBJ) $(B_OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(B_NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean bonus