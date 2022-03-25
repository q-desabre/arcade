

SRC=	src/Snake.cpp		\
		src/SnakeGame.cpp	\
		../AGame.cpp		\
		../../core/src/Clock.cpp

OBJ=		$(SRC:.cpp=.o)

CPPFLAGS=	-fPIC -I./include -I../../core/include -I../

NAME=		../../lib/lib_game_snake.so

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -shared $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
