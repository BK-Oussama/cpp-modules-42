


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCs = BitcoinExchange.cpp main.cpp
HDRs = BitcoinExchange.hpp
NAME = btc

all: $(NAME)

$(NAME): $(SRCs) $(HDRs) 
	$(CC) $(CFLAGS) $(SRCs) -o $(NAME)
	
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME)
re: clean all