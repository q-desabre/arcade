RESET          = \033[0m
make_std_color = \033[3$1m      # defined for 1 through 7
make_color     = \033[38;5;$1m  # defined for 1 through 255
SUC_COLOR = $(strip $(call make_std_color,2))
PEN_COLOR = $(strip $(call make_std_color,6))
ERR_COLOR = $(strip $(call make_std_color,7))
STD_COLOR = $(strip $(call make_color,8))

all:
		@make -C core/
		@make -C games/Snake/
		@make -C games/Menu/
		@make -C graphics/Sfml/

clean:
		make -C core/ clean
		make -C games/Menu clean
		make -C graphics/Sfml/ clean
		make -C graphics/Ncurses/ clean
		make -C games/Snake/ clean 

fclean:	
		make -C core/ fclean 
		make -C graphics/Sfml/ fclean 
		make -C graphics/Ncurses/ fclean 
		make -C games/Snake/ fclean 
		make -C games/Menu/ fclean 

re:		fclean all
