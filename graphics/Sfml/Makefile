

SRC=		src/SfmlGraphic.cpp		\
		../../core/src/Clock.cpp

OBJ=		$(SRC:.cpp=.o)

CPPFLAGS=	-fPIC -I./include -I../../core/include 

NAME=		../../lib/lib_sfml.so

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -shared $(OBJ) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
