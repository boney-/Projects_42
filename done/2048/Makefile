SRC =	main.c \
		check_end.c \
		draw_line.c \
		game_screen.c \
		init.c \
		keypress.c \
		menu.c \
		merge.c \
		move.c \
		print.c \
		rand.c

LIB = libft/libft.a

COL_ON = \033[0;32m
COL_OFF = \033[m

CFLAGS =  -Wall -Wextra -Werror -lncurses
INC = -I libft/includes/

MKLIB = make -C libft/
CLNLIB = make -C libft/ clean
FCLNLIB = make -C libft/ fclean
NAME = game_2048
CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MKLIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o:%.c 
	$(CC) $(CFLAGS) -c  $< $(INC)

clean:
	$(CLNLIB)
	rm -f $(OBJ)

fclean: clean
	$(FCLNLIB)
	rm $(NAME)

re: fclean all
