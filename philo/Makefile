# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 15:40:46 by hyobicho          #+#    #+#              #
#    Updated: 2023/04/13 21:42:02 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread
SRCS = \
ft_main.c \
ft_utils.c \
ft_init.c \
ft_time.c \
ft_routine.c \
ft_monitor.c \
ft_pthread_utils.c \
ft_positive_atoi.c
M_OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJ)
	@$(CC) $(M_OBJ) $(CFLAGS) -o $(NAME)

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(M_OBJ)

fclean: clean
	@rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean
