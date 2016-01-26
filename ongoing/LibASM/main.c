/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 19:12:28 by jbonnet           #+#    #+#             */
/*   Updated: 2016/01/21 17:49:22 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isprint(int c);
int		ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, char *s2);
char	*ft_memset(char *s1, int c, size_t n);
int		ft_puts(char *str);
char	*ft_strdup(const char *s1);
void	ft_cat(int c);

char	*randomstr(void)
{
	int	i;
	int nb;
	char	*random = (char *)malloc(sizeof(*random) * 21);

	i = 0;
	while (i < 20)
	{
		nb = (rand() + nb) % 126;
		if (isprint(nb))
			random[i++] = nb;
		else
			nb += nb;
	}
	random[i] = '\0';
	return (random);
}


int		main(int argc, char **argv)
{
	int fd;
	char buf[21];
	char *str2;
	char *str1;
	char *str3;
	int retsys;
	int retuser;
	int ret;
	int out;
	int pfd[2];
	char bufer[4][21];
	int i = -1;
	
	if (argc == 1)
	{
		(void)argv;
		puts("if you want to test cat with a file use:\n ./a.out [file]");
		srand(time(NULL));
		str1 = randomstr();
		str2 = randomstr();
		str3 = randomstr();
		// ISALPHA TEST
		while (i++ < 127)
		{
			if (ft_isalpha(i) != isalpha(i))
			{
				printf("isalpha \033[31mK.O.\033[0m");
				break;
			}
		}
		if (i == 128)
			puts("isalpha \033[32mOK!\033[0m");
		i = -1;
		// ISDIGIT TEST
		while (i++ < 127)
		{
			if (ft_isdigit(i) != isdigit(i))
			{
				puts("isdigit \033[31mK.O.\033[0m");
				break;
			}
		}
		if (i == 128)
			puts("isdigit \033[32mOK!\033[0m");
		i = -1;
		// ISALNUM TEST
		while (i++ < 127)
		{
			if (ft_isalnum(i) != isalnum(i))
			{
				puts("isalnum \033[31mK.O.\033[0m");
				break;
			}
		}
		if (i == 128)
			puts("isalnum \033[32mOK!\033[0m");
		i = -1;
		// ISASCII TEST
		while (i++ < 127)
		{
			if (ft_isascii(i) != isascii(i))
			{
				puts("isascii \033[31mK.O.\033[0m");
				break;
			}
		}
		if (i == 128)
			puts("isascii \033[32mOK!\033[0m");
		i = -1;
		// ISPRINT TEST
		while (i++ < 127)
		{
			if (ft_isprint(i) != isprint(i))
			{
				puts("isprint \033[31mK.O.\033[0m");
				break;
			}
		}
		if (i == 128)
			puts("isprint \033[32mOK!\033[0m");
		i = -1;
		// TOUPPER TEST
		while (i++ < 127)
		{
			if (ft_toupper(i) != toupper(i))
			{
				puts("toupper \033[31mK.O.\033[0m");
				break;
			}
		}
		if (i == 128)
			puts("toupper \033[32mOK!\033[0m");
		i = -1;
		// TOLOWER TEST
		while (i++ < 127)
		{
			if (ft_tolower(i) != tolower(i))
			{
				puts("tolower \033[31mK.O.\033[0m");
				break;
			}
		}
		if (i == 128)
			puts("tolower \033[32mOK!\033[0m");
		i = -1;
		// BZERO TEST
		ft_bzero(str3, 7);
		i = 0;
		while (i < 7)
		{
			if (str3[i] != '\0')
			{	
				printf("bzero \033[31mK.O.\033[0m");
				break ;
			}
			i++;
		}
		if (i == 7)
			puts("bzero \033[32mOK!\033[0m");
		// STRLEN TEST
		if (ft_strlen(str1) == strlen(str1) && ft_strlen("") == strlen(""))
			puts("strlen \033[32mOK!\033[0m");
		else
			puts("strlen \033[31mK.O.\033[0m");
		// MEMSET TEST
		ft_memset(str3, 'A', 5);
		if (memcmp(str3, "AAAAA", 5) == 0)
			puts("memset \033[32mOK!\033[0m");
		else
			puts("memset \033[31mK.O.\033[0m");
		// MEMCPY TEST
		ft_memcpy(str3, str1, 21);
		if (memcmp(str1, str3, 21) == 0)
			puts("memcpy \033[32mOK!\033[0m");
		else
			puts("memcpy \033[31mK.O.\033[0m");
		// STRDUP TEST
		free(str1);
		str1 = randomstr();
		if (strcmp(ft_strdup("bonjour fucker."), "bonjour fucker.") == 0)
			puts("strdup (normal str) \033[32mOK!\033[0m");
		else
			puts("strdup (normal str) \033[31mK.O.\033[0m");
		if (strcmp(ft_strdup(str1), str1) == 0)
			puts("strdup (random str) \033[32mOK!\033[0m");
		else
			puts("strdup (random str) \033[31mK.O.\033[0m");
		// STRCAT TEST
		bzero(buf, 21);
		ft_strcat(buf, "");
		ft_strcat(buf, "Hell");
		ft_strcat(buf, "");
		ft_strcat(buf, "o");
		ft_strcat(buf, " Wo");
		ft_strcat(buf, "rld!");
		ft_strcat(buf, "");
		if (strcmp(buf, "Hello World!") == 0)
			puts("strcat \033[32mOK!\033[0m");
		else
			puts("strcat \033[31mK.O.\033[0m");

		// PUTS TEST
		out = dup(1);
		pipe(pfd);
		dup2(pfd[1], 1);	
		retuser = ft_puts(str1);
		read(pfd[0], bufer[0], 21);
		retsys = puts(str1);
		read(pfd[0], bufer[1], 21);
		ft_puts(NULL);
		ret = read(pfd[0], bufer[2], 7);
		puts(NULL);
		read(pfd[0], bufer[3], 7);
		bufer[0][20] = '\0';
		bufer[1][20] = '\0';
		bufer[2][ret] = '\0';
		bufer[3][ret] = '\0';
		dup2(out, 1);
		close(pfd[0]);
		close(pfd[1]);
		if (retsys == retuser)
			puts("puts (return value) \033[32mOK!\033[0m");
		else
			puts("puts (return value) \033[31mK.O.\033[0m");
		if (strcmp(bufer[0], bufer[1]) == 0)
			puts("puts (random string) \033[32mOK!\033[0m");
		else
			puts("puts (random string) \033[31mK.O.\033[0m");
		if (strcmp(bufer[2], bufer[3]) == 0)
			puts("puts (Null value) \033[32mOK!\033[0m");
		else
			puts("puts (Null value) \033[31mK.O.\033[0m");
		puts("\nTest of function ft_cat on standrd input:\n\033[31mCTRL + D\033[0m to end.");
		ft_cat(0);
		free(str1);
		free(str2);
		free(str3);
	}
	else if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		ft_cat(fd);
		if ((close(fd)) == -1)
			return (-1);
	}
	return (0);
}
