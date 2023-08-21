# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/17 15:08:02 by hyobicho          #+#    #+#              #
#    Updated: 2023/07/17 15:25:00 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombieHorde
C++ = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(OBJ) $(CXXFLAGS) -o $(NAME)

.o: %.cpp
	$(C++) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all re clean fclean
