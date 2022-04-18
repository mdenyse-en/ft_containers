NAME	= contain

NAME_B	= contain_bonus

INC		= ./includes

INCS	= ./includes/stack.hpp \
		./includes/vector.hpp \
		./includes/iterators.hpp \
		./includes/map.hpp \
		./includes/RBTree.hpp

INCS_B	= ./includes/iterators.hpp \
		./includes/set.hpp \
		./includes/RBTree.hpp

SRCS	= ./sources/my_main.cpp
# ./sources/main.cpp

SRCS_B	= ./sources/my_main_bonus.cpp
		
#		./sources/stack.cpp

OBJS	= $(SRCS:.cpp=.o)

OBJS_B	= $(SRCS_B:.cpp=.o)

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
		$(RM) $(OBJS) $(OBJS_B)
		@echo Objects files is clear!

fclean:	clean
		$(RM) $(NAME) $(NAME_B)
		@echo All cleaned!

re:		fclean all

bonus:	$(OBJS_B) $(INCS_B)
		$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME_B)
		@echo $(NAME_B) is compiled!
