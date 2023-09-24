NAME = zombie
C++ = c++ -std=c++98
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
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
