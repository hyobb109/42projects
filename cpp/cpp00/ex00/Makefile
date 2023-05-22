NAME = megaphone
C++ = c++ #-std=c++98
CFLAGS = -Wall -Wextra -Werror
SRCS = megaphone.cpp
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
