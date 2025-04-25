

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCs = *.cpp 
HDRs = *.hpp

NAME = phonebook

all: $(NAME)

$(NAME): $(SRCs)
	$(CC) $(CFLAGS) $(SRCs) -o $(NAME)
	
clean:
	rm -f $(NAME)

re: clean all