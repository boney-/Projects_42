SRC =	fdf.c \
		get_next_line.c \
		ft_parse.c \
		ft_key_hook.c \
		ft_draw.c \
		main.c


LIB = -L/usr/X11/lib -lmlx -lXext -lX11 libft/libft.a

COL_ON = \033[0;32m
COL_OFF = \033[m

CFLAGS =  -Wall -Wextra -Werror 
INC = -I includes/

MKLIB = make -C libft/
CLNLIB = make -C libft/ clean
FCLNLIB = make -C libft/ fclean
NAME = fdf

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MKLIB)
	@echo "${COL_ON} LIB [OK] ${COL_OFF}"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "${COL_ON} FDF [OK] ${COL_OFF}"


%.o:%.c 
	@$(CC) $(CFLAGS) -c  $< $(INC)

clean:
	@$(CLNLIB)
	@rm -f $(OBJ)

fclean: clean
	@$(FCLNLIB)
	@-rm $(NAME)

re: fclean all
