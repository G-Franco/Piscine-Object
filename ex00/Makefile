# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 10:53:19 by gacorrei          #+#    #+#              #
#    Updated: 2024/07/30 17:56:48 by gacorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bank
DNAME = bank_debug
SRC = main.cpp Account.cpp Bank.cpp
CC = @c++
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -g -std=c++98
CFLAGS_DEBUG = -Wall -Wextra -Werror -pedantic -Wshadow -g -std=c++98 -fsanitize=address,undefined

all: 		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(CFLAGS) $^ -o $@

debug:		$(DNAME)

$(DNAME):	$(SRC)
			$(CC) $(CFLAGS_DEBUG) $^ -o $@

clean:
# This is intentionally blank

fclean:		clean
			@rm -f $(NAME) $(DNAME)

re: 		fclean all

re_debug:	fclean debug

run:		all
			./$(NAME)

.PHONY: all debug clean fclean re re_debug run