


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCs = Serializer.cpp main.cpp
HDRs = Serializer.hpp
NAME = executeMe

all: $(NAME)

$(NAME): $(SRCs) $(HDRs) 
	$(CC) $(CFLAGS) $(SRCs) -o $(NAME)
	
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME)
re: clean all