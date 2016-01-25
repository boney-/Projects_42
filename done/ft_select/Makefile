SRC =	select.c \
		tab_to_lst.c \
		cursor_selection.c \
		delete_current.c \
		exit.c \
		get_max_element_size.c \
		get_winsize.c \
		init.c \
		list_param.c \
		print_list.c \
		print_out.c \
		puts_cmd.c \
		puts_str.c \
		read_loop.c

LIB = libft/libft.a

COL_ON = \033[0;32m
COL_OFF = \033[m

CFLAGS =  -Wall -Wextra -Werror -ltermcap
INC = -I libft/includes/

MKLIB = make -C libft/
CLNLIB = make -C libft/ clean
FCLNLIB = make -C libft/ fclean
NAME = ft_select 
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
