

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCs = *.cpp 
HDRs = *.hpp

NAME = megaphone

all: $(NAME)

$(NAME): $(SRCs)
	$(CC) $(CFLAGS) $(SRCs) -o $(NAME)
	
clean:
	rm -f $(NAME)

# fclean: clean
# 	rm -f $(NAME) NOT ASKED

re: clean all