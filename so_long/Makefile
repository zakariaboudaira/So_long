# _*_ MakeFile _*_

NAME = so_long

CC = cc

FUNC = functions/functions.a


SRCS = set_up_map.c  set_window.c so_long.c move_player.c move_right.c move_down.c move_up.c move_left.c move_enemy.c set_coins.c

ICLS = so_long.h

all: $(NAME)

$(NAME):    $(SRCS)
	cd functions && make && cd ..
	$(CC) -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRCS) $(FUNC) -o $(NAME)

bonus : $(NAME)

clean : 
	cd functions && make clean && cd ..
	
fclean :	clean
	rm -f $(FUNC) $(NAME)

re : fclean all

.PHONY: re all fclean clean