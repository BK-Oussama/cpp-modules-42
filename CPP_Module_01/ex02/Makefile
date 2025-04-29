


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCs = *.cpp 

NAME = ExecuteMe

all: $(NAME)

$(NAME): $(SRCs)
	$(CC) $(CFLAGS) $(SRCs) -o $(NAME)
	
clean:
	rm -f $(NAME)

re: clean all