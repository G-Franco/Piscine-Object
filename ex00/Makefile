NAME = bank
DEBUG = bank
SRC = src/main.cpp src/Bank.cpp src/Account.cpp
CC = @c++
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++98
CFLAGS_DEBUG = -Wall -Wextra -Werror -pedantic -Wshadow -DTEST -std=c++98 -g -fsanitize=address,undefined

all:			$(NAME)

$(NAME):	$(SRC)
					$(CC) $(CFLAGS) $^ -o $@ 

debug:		$(DEBUG)

$(DEBUG):	$(SRC)
					$(CC) $(CFLAGS_DEBUG) $^ -o $@ 

clean:

fclean:
					@rm -rf $(NAME)

re:				fclean all

re_debug:	fclean debug

PHONY: all debug clean fclean re re_debug