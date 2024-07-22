# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 10:53:19 by gacorrei          #+#    #+#              #
#    Updated: 2024/07/22 17:11:09 by gacorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = div_rule
SRC = main.cpp Account.cpp Bank.cpp
CC = @c++
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -g -std=c++98
CFLAGS_DEBUG = -Wall -Wextra -Werror -pedantic -Wshadow -g -std=c++98 -fsanitize=address,undefined

all: 		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(CFLAGS) $^ -o $@

debug:		$(SRC)
			$(CC) $(CFLAGS_DEBUG) $^ -o $@

clean:
# This is intentionally blank

fclean:		clean
			@rm -f $(NAME) debug

re: 		fclean all

re_debug:	fclean debug

run:		all
			./$(NAME)

.PHONY: all debug clean fclean re re_debug run