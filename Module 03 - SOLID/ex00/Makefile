NAME = solid1
DEBUG = solid1_debug
SRC = src/main.cpp \
			src/car.cpp \
			src/Engine.cpp \
			src/Gearbox.cpp \
			src/Pedals.cpp \
			src/Steering.cpp
CC = @c++
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++98
CFLAGS_DEBUG = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++98 -g -fsanitize=address,undefined

all:			$(NAME)

$(NAME):	$(SRC)
					$(CC) $(CFLAGS) $^ -o $@

debug:		$(DEBUG)

$(DEBUG):	$(SRC)
					$(CC) $(CFLAGS_DEBUG) $^ -o $@

clean:

fclean:
					@rm -rf $(NAME) $(DEBUG)

re:				fclean all

re_debug:	fclean debug

PHONY: all debug clean fclean re re_debug