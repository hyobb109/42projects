# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:43:15 by hyobicho          #+#    #+#              #
#    Updated: 2022/11/23 20:17:09 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = \
ft_printf.c \
ft_convert_hex.c \
ft_putnbr_a.c \
ft_strchar.c
M_OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJ)
	ar rc $@ $^

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(M_OBJ)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all re clean fclean