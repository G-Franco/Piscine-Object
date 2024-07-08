# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacorrei <gacorrei@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 10:53:19 by gacorrei          #+#    #+#              #
#    Updated: 2024/07/08 10:59:34 by gacorrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = div_rule
SRC = main.cpp DivideAndRule.cpp
CC = @c++
CFLAGS = -Wall -Wextra -Werror -pedantic -Wshadow -g -std=c++98 -fsanitize=address,undefined

all: 		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(CFLAGS) $^ -o $@

clean:
# This is intentionally blank

fclean:		clean
			rm -f $(NAME)

re: 		fclean all

run:		all
			./$(NAME)

.PHONY: all clean fclean re