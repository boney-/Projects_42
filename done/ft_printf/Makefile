SRC =	ft_char.c \
		ft_init.c \
		ft_p.c \
		ft_treat_int.c \
		ft_check_flags.c \
	   	ft_init_mask.c \
  		ft_parse.c \
		ft_up_flags.c \
		ft_dec_to_bin.c \
   		ft_itoa_long.c \
  		ft_printf.c \
		ft_wide_print.c \
		ft_dec_to_hex.c \
   		ft_itoa_ulong.c \
   		ft_space_precision.c \
		ft_wide_things.c \
		ft_dec_to_oct.c \
   		ft_justification.c \
	  	ft_string.c \
		ft_wstrlen.c \
		ft_exec.c \
		ft_oux.c \
		ft_tools.c

LIB = libft/libft.a

COL_ON = \033[0;32m
COL_OFF = \033[m

CFLAGS =  -Wall -Wextra -Werror 
INC = -I libft/includes/

MKLIB = make -C libft/
CLNLIB = make -C libft/ clean
FCLNLIB = make -C libft/ fclean
NAME = libftprintf.a
CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MKLIB)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	libtool -static -o libftprintf.a libft/libft.a libftprintf.a 

%.o:%.c 
	$(CC) $(CFLAGS) -c  $< $(INC)

clean:
	$(CLNLIB)
	rm -f $(OBJ)

fclean: clean
	$(FCLNLIB)
	rm $(NAME)

re: fclean all
