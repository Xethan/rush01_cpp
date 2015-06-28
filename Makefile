# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/24 19:38:05 by ncolliau          #+#    #+#              #
#    Updated: 2015/06/28 09:54:45 by mgouault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	module/RAMInfo.class.cpp module/CPUInfo.class.cpp module/Time.class.cpp \
		module/HostUserNames.class.cpp module/OSInfo.class.cpp \
		module/CPUUsage.class.cpp module/NetworkUsage.class.cpp \
		display/Ncurses.class.cpp Monitor.class.cpp main.cpp

HEADER = -I ./ -I ./display/ -I ./module/

NAME = ft_gkrellm

CC = clang++

FLAGS = -Wall -Wextra -Werror

LIB = -lncurses

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(FLAGS) -o $(NAME) $(SRC) $(HEADER) $(LIB)

clean:
		@rm -f $(NAME)
		@echo "clean done"

fclean: clean
		@rm -f $(NAME)
		@echo "fclean done"

re: fclean all

.PHONY: make, all, $(NAME), clean, fclean, re
