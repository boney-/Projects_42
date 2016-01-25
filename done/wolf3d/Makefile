SRC =	main.c \
		get_next_line.c \
		ft_key_hook.c \
		ft_controls.c \
		ft_draw.c \
		ft_calc.c \
		ft_init.c 


LIB = -L/usr/X11/lib -lmlx -lXext -lX11  libft/libft.a

COL_ON = \033[0;32m
COL_OFF = \033[m

CFLAGS =  -Wall -Wextra -Werror 
INC = -I libft/includes/

MKLIB = make -C libft/
CLNLIB = make -C libft/ clean
FCLNLIB = make -C libft/ fclean
NAME = wolf3d

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MKLIB)
	@echo "${COL_ON} LIB [OK] ${COL_OFF}"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "${COL_ON} Wolf [OK] ${COL_OFF}"


%.o:%.c 
	@$(CC) $(CFLAGS) -c  $< $(INC) -I /usr/X11/include

clean:
	@$(CLNLIB)
	@rm -f $(OBJ)

fclean: clean
	@$(FCLNLIB)
	@-rm $(NAME)

re: fclean all
