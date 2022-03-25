
SRC=		src/main.cpp		\
		src/Clock.cpp		\
		src/Core.cpp		\
		src/DynamicLoader.cpp	\

OBJ=		$(SRC:.cpp=.o)

CPPFLAGS=	-I./include -g3

LDFLAGS=	-ldl -Wl,-rpath=./../lib/

NAME=		../arcade

all:		$(NAME)

$(NAME):	$(OBJ)
		g++  $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all fclean clean re
