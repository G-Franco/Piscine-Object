NAME = trains
DEBUG = trains_debug
SRC = src/main.cpp \
			src/File_checker.cpp \
			src/AValidation.cpp \
			src/Node_validation.cpp \
			src/Rail_validation.cpp \
			src/Train_validation.cpp \
			src/Railway_factory.cpp \
			src/Train.cpp

CC = @c++
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++14
CFLAGS_DEBUG = -Wall -Wextra -Werror -pedantic -Wshadow -std=c++14 -g -fsanitize=address,undefined

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