# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:24:59 by hyobicho          #+#    #+#              #
#    Updated: 2023/01/26 03:45:12 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_FLAG = -Llibft -lft
SRCS = \
ft_main.c \
ft_rules.c
B_SRCS = ft_checker.c
M_OBJ = $(SRCS:.c=.o)
B_OBJ = $(B_SRCS:.c=.o)
LIBFT_DIR = ./libft/
INC_DIR = ./include/

all: $(NAME)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(M_OBJ) $(B_OBJ) $(LIBFT_FLAG) $(CFLAGS) -o $(NAME)

$(NAME): $(M_OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(M_OBJ) $(LIBFT_FLAG) $(CFLAGS) -o $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

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