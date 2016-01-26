SRC =	ft_bzero.s \
		ft_isalpha.s \
		ft_isdigit.s \
		ft_memcpy.s \
		ft_strlen.s \
		ft_toupper.s \
		ft_tolower.s \
		ft_isprint.s \
		ft_isalnum.s \
		ft_isascii.s \
		ft_strcat.s \
		ft_strdup.s \
		ft_memset.s \
		ft_puts.s \
		ft_cat.s

FLAGS =  -f macho64

OBJ = $(SRC:.s=.o)
	NAME = libfts.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.s
	nasm $(FLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	-rm $(NAME)

re: fclean all
