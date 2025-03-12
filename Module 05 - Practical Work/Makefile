NAME = trains
DEBUG = trains_debug
TEST = train_test
SRC = $(wildcard src/*.cpp)
TEST_SRC = $(wildcard test/*.cpp)
COMMON = $(filter-out src/main.cpp, $(SRC))

CC = @c++
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++17
CFLAGS_DEBUG = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++17 -g -fsanitize=address,undefined

all:			$(NAME)

$(NAME):	$(SRC)
					$(CC) $(CFLAGS) $^ -o $@

debug:		$(DEBUG)

$(DEBUG):	$(SRC)
					$(CC) $(CFLAGS_DEBUG) $^ -o $@

test:			$(TEST)

$(TEST):	$(TEST_SRC) $(COMMON)
					$(CC) $(CFLAGS_DEBUG) $^ -o $@

fclean:
					@rm -rf $(NAME) $(DEBUG) $(TEST)

re:				fclean all

re_debug:	fclean debug

PHONY: all debug fclean re re_debug