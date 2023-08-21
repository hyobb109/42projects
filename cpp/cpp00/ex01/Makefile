# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 17:51:39 by hyobicho          #+#    #+#              #
#    Updated: 2023/07/17 15:23:41 by hyobicho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
C++ = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Contact.cpp Phonebook.cpp
OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(OBJ) $(CXXFLAGS) -o $(NAME)

%.o : %.cpp
	$(C++) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all re clean fclean
