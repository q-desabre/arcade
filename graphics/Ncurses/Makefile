

SRC=		src/NcursesGraphic.cpp		\
		../../core/src/Clock.cpp

OBJ=		$(SRC:.cpp=.o)

CPPFLAGS=	-fPIC -I./include -I../../core/include 

NAME=		../../lib/lib_graphic_ncurses.so

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -shared $(OBJ) -o $(NAME) -lncurses

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
