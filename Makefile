# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/24 19:38:05 by ncolliau          #+#    #+#              #
#    Updated: 2015/06/27 20:17:55 by mgouault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	RAMInfo.Class.cpp CPUInfo.Class.cpp Time.Class.cpp \
		HostUserNames.Class.cpp OSInfo.Class.cpp \
		Ncurses.Class.cpp Monitor.Class.cpp main.cpp

NAME = ft_gkrellm

CC = clang++

FLAGS = -Wall -Wextra -Werror

LIB = -lncurses

.PHONY: make, all, $(NAME), clean, fclean, re

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB)

clean:
		@rm -f $(NAME)
		@echo "clean done"

fclean: clean
		@rm -f $(NAME)
		@echo "fclean done"

re: fclean all
