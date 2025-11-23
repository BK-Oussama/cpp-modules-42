


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCs = PmergeMe.cpp main.cpp
HDRs = PmergeMe.hpp
NAME = PmergeMe

all: $(NAME)

$(NAME): $(SRCs) $(HDRs) 
	$(CC) $(CFLAGS) $(SRCs) -o $(NAME)
	
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME)
re: clean all