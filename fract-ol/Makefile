# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:24:59 by hyobicho          #+#    #+#              #
#    Updated: 2023/02/09 04:57:19 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = \
ft_main.c
M_OBJ = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME)

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(M_OBJ) $(B_OBJ)
	$(CC) $(M_OBJ) $(B_OBJ) $(LIBFT_FLAG) $(CFLAGS) -o $(NAME)
else
$(NAME): $(M_OBJ)
	$(CC) $(M_OBJ) $(LIBFT_FLAG) $(CFLAGS) -o $(NAME)
endif

%.o : %.c
	$(CC) -c $(CFLAGS) -Imlx $< -o $@

clean:
	rm -f $(M_OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME) $(B_NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean bonus