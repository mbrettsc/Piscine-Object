NAME = main
SRC = Bank.cpp main.cpp
CFLAGS = -Wall -Wextra -Werror
CC = c++ -std=c++98

all: $(NAME)

$(NAME):
	$(CC) $(CLFAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all, clean, fclean, re 