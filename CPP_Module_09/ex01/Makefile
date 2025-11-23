


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCs = RPN.cpp main.cpp
HDRs = RPN.hpp
NAME = RPN

all: $(NAME)

$(NAME): $(SRCs) $(HDRs) 
	$(CC) $(CFLAGS) $(SRCs) -o $(NAME)
	
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME)
re: clean all