SRC =	push_swap.c \
		tab_to_lst.c \
		push.c \
		rotate.c \
		swap.c \
		stack_push.c \
		lst_new.c \
		print_lst.c \
		options.c \
		is_list_sorted.c \
		misc.c \
		sort.c \
		overflow.c \
		max_min.c

LIB = libft/libft.a

COL_ON = \033[0;32m
COL_OFF = \033[m

CFLAGS =  -Wall -Wextra -Werror 
INC = -I libft/includes/

MKLIB = make -C libft/
CLNLIB = make -C libft/ clean
FCLNLIB = make -C libft/ fclean
NAME = push_swap 
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
