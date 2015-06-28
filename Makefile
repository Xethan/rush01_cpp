QTINCLUDES	=	-I $(HOME)/Qt/5.4/Src/qtbase/include \
				-I $(HOME)/Qt/5.4/Src/qtbase/include/QtCore \
				-I $(HOME)/Qt/5.4/Src/qtbase/include/QtGui \
				-I $(HOME)/Qt/5.4/Src/qtbase/include/QtWidgets

LFLAGS		=	-F $(HOME)/Qt/5.4/clang_64/lib -framework QtCore -framework QtGui -framework QtWidgets

SRC			=	module/RAMInfo.class.cpp module/CPUInfo.class.cpp module/Time.class.cpp \
				module/HostUserNames.class.cpp module/OSInfo.class.cpp \
				module/CPUUsage.class.cpp module/NetworkUsage.class.cpp \
				display/Ncurses.class.cpp display/QtDisplay.class.cpp Monitor.class.cpp main.cpp
HEADER		=	-I ./ -I ./display/ -I ./module/
NAME		=	ft_gkrellm
CC			=	clang++
CFLAGS		=	-Wall -Wextra -Werror
LIB			=	-lncurses

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(SRC) $(HEADER) $(QTINCLUDES) $(LIB)

clean:
		@rm -f $(NAME)
		@echo "clean done"

fclean: clean
		@rm -f $(NAME)
		@echo "fclean done"

re: fclean all

.PHONY: make, all, $(NAME), clean, fclean, re
