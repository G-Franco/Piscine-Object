NAME = trains
DEBUG = trains_debug
SRC = src/main.cpp \
			src/File_checker.cpp

T_FILE = test/test_file_checker.cpp

CC = @c++
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++11
CFLAGS_DEBUG = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++11 -g -fsanitize=address,undefined

all:			$(NAME)

$(NAME):	$(SRC)
					$(CC) $(CFLAGS) $^ -o $@

debug:		$(DEBUG)

$(DEBUG):	$(SRC)
					$(CC) $(CFLAGS_DEBUG) $^ -o $@

t_files:	$(DEBUG)

$(DEBUG):	$(SRC) $(T_FILE)
					$(CC) $(CFLAGS_DEBUG) $^ -o $@

clean:

fclean:
					@rm -rf $(NAME) $(DEBUG)

re:				fclean all

re_debug:	fclean debug

PHONY: all debug clean fclean re re_debug