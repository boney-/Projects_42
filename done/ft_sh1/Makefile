SRC =	main.c \
		get_next_line.c \
		ft_env.c \
		ft_cd.c \
		ft_get.c \
		ft_check.c \
		ft_misc.c \
		ft_lstdel_onelink.c \
		ft_pwd.c \
		ft_prompt.c \
		ft_handler.c \
		ft_exit.c \
		ft_exec.c


LIB = libft/libft.a

COL_ON = \033[0;32m
COL_OFF = \033[m

CFLAGS =  -Wall -Wextra -Werror 
INC = -I libft/includes/

MKLIB = make -C libft/
CLNLIB = make -C libft/ clean
FCLNLIB = make -C libft/ fclean
NAME = ft_minishell1

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MKLIB)
	@echo "${COL_ON} LIB [OK] ${COL_OFF}"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "${COL_ON} SH1 [OK] ${COL_OFF}"


%.o:%.c 
	@$(CC) $(CFLAGS) -c  $< $(INC) -I libft/includes/

clean:
	@$(CLNLIB)
	@rm -f $(OBJ)

fclean: clean
	@$(FCLNLIB)
	@-rm $(NAME)

re: fclean all
