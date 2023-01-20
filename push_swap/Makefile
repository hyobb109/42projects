# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:24:59 by hyobicho          #+#    #+#              #
#    Updated: 2023/01/20 21:39:01 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_FLAG = -Llibft -lft
SRCS = \
ft_main.c \
ft_rules.c
B_SRCS = checker.c
M_OBJ = $(SRCS:.c=.o)
B_OBJ = $(B_SRCS:.c=.o)
LIBFT_DIR = ./libft/
INC_DIR = ./include/

all: $(NAME)

bonus: $(NAME)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(M_OBJ) $(B_OBJ)
	ar rc $@ $^
else
$(NAME): $(M_OBJ)
	ar rc $@ $^
endif

%.o : %.c
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

clean:
	rm -f $(M_OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean bonus