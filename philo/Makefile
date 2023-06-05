# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 15:40:46 by hyobicho          #+#    #+#              #
#    Updated: 2023/06/05 19:28:29 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread
SRCS = \
main.c \
main_utils.c \
positive_atoi.c \
pthread_utils.c \
philo_init.c \
philo_routine.c \
philo_status.c \
time_utils.c \
fork_utils.c \
monitor.c
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
