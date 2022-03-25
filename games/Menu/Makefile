

SRC=		src/Menu.cpp		\
			src/DirectoryReader.cpp \
			../AGame.cpp


OBJ=		$(SRC:.cpp=.o)

CPPFLAGS=	-fPIC -I./include -I../../core/include -I../

NAME=		../../lib/lib_menu.so

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -shared $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
