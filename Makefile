NAME	= contain

INCS	= ./includes/stack.hpp \
		./includes/vector.hpp \
		./includes/iterators.hpp
#		./includes/map.hpp

SRCS	= ./sources/my_main.cpp \
#		./sources/stack.cpp

OBJS	= $(SRCS:.cpp=.o)

CFLAGS	= -Wall -Wextra -Werror -std=c++98

CC		= clang++

RM		= rm -rf

%.o:	%.cpp $(INCS)
	$(CC) $(CFLAG) -c $< -o $@

.PHONY:	all, clean, fclean, re

$(NAME):	$(OBJS) $(INCS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo $(NAME) is compiled!

all:	$(NAME)

clean:	
		$(RM) $(OBJS)
		@echo Objects files is clear!

fclean:	clean
		$(RM) $(NAME)
		@echo All cleaned!

re:		fclean all
