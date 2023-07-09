# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 17:51:39 by hyobicho          #+#    #+#              #
#    Updated: 2023/07/09 19:38:15 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
C++ = c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Contact.cpp Phonebook.cpp
M_OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(M_OBJ)
	$(C++) $(M_OBJ) $(CFLAGS) -o $(NAME)

%.o : %.c
	$(C++) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(M_OBJ)

fclean: clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean
