# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 17:51:21 by hyobicho          #+#    #+#              #
#    Updated: 2023/07/17 15:23:33 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
C++ = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
SRCS = megaphone.cpp
M_OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(M_OBJ)
	$(C++) $(M_OBJ) $(CXXFLAGS) -o $(NAME)

%.o : %.cpp
	$(C++) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(M_OBJ)

fclean: clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean
