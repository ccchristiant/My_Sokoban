##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	$(SRC_DIR)main.c	\
		$(SRC_DIR)manual.c	\
		$(SRC_DIR)error.c	\
		$(SRC_DIR)sokoban.c	\
		$(SRC_DIR)init_end_term.c	\
		$(SRC_DIR)game_loop.c	\
		$(SRC_DIR)display.c	\
		$(SRC_DIR)reset_map_i.c	\
		$(SRC_DIR)moves.c	\
		$(SRC_DIR)upd_moves.c	\
		$(SRC_DIR)blocked.c	\
		$(SRC_DIR)put_back_loc.c	\

SRC_DIR = src/

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-Iinclude

LDFLAGS	=	-Llib/my

LDLIBS	=	-lmy -lncurses

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	make -C lib/my clean
	rm -f $(OBJ)

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
