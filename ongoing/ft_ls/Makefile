SRC =	ft_ls.c \
		display_ls.c \
		perms_ls.c \
		mod_ls.c

LIB = libft/libft.a

CFLAGS =  -Wall -Wextra -Werror
INC = -I libft/

MKLIB = make -C libft/
CLNLIB = make -C libft/ clean
FCLNLIB = make -C libft/ fclean
NAME = ft_ls

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MKLIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)


%.o:%.c 
	$(CC) $(FLAGS) -c  $< $(INC)

clean:
	@$(CLNLIB)
	rm -f $(OBJ)

fclean: clean
	@$(FCLNLIB)
	-rm $(NAME)

re: fclean all
