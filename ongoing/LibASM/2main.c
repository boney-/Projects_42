#include <fcntl.h>

void	ft_cat(int fd);

int
main(int ac, const char **av) {
	ft_cat(0);
	ft_cat(open(__FILE__, O_RDONLY));
	ft_cat(open(av[0], O_RDONLY));
	ft_cat(-42);
	(void)ac;
	return (0);
}
