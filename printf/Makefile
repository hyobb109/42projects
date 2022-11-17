# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:43:15 by hyobicho          #+#    #+#              #
#    Updated: 2022/11/17 17:28:16 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
SRCS = \
ft_printf.c

M_OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJ)
	ar rc $^

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(M_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean