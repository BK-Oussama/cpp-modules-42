


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCs = Bureaucrat.cpp  main.cpp
HDRs = Bureaucrat.hpp
NAME = executeMe

all: $(NAME)

$(NAME): $(SRCs) $(HDRs) 
	$(CC) $(CFLAGS) $(SRCs) -o $(NAME)
	
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME)
re: clean all