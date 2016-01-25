/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloeung <aloeung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 21:30:59 by aloeung           #+#    #+#             */
/*   Updated: 2016/01/02 17:43:05 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>

int     ft_isalpha(int c);
int     ft_isdigit(int c);
size_t  ft_strlen(const char *s);
void    *ft_memcpy(void *dst, void *src, size_t n);
int     ft_tolower(int c);
int     ft_toupper(int c);
int     ft_isprint(int c);
int     ft_bzero(void *s, size_t n);
char    *ft_strcat(char *s1, char *s2);
char    *ft_memset(char *s1, int c, size_t n);
int     ft_puts(char *str);
char    *ft_strdup(char *s1);

void	del(char **s)
{
	free(*s);
	*s = NULL;
}

int		my_strequ(char const *s1, char const *s2)
{
	return ((s1 && s2) && !strcmp(s1, s2) ? 1 : 0);
}

int		my_strnequ(char const *s1, char const *s2, size_t n)
{
	return ((s1 && s2) && !strncmp(s1, s2, n) ? 1 : 0);
}

void	my_putstr(char *str)
{
	if (str)
		write(1, str, strlen(str));
	else
		my_putstr("(null)");
}

void	my_ppstr(unsigned int i, char *str)
{
	write(1, str, strlen(str));
	(void)i;
}

void        my_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		while (*s)
			f(s++);
	}
}

void	my_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	i = 0;
	if (s && f)
	{
		while (*s)
			f(i++, s++);
	}
}

int		my_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (s1 && s2 && n)
	{
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		while (str1[i] == str2[i] && i < (n - 1))
			i++;
		return (str1[i] - str2[i]);
	}
	return (0);
}

int		memcmp_assert(void *s1, void *s2, size_t n)
{
	assert(memcmp(s1, s2, n) == 0);
	return (0);
}

char	*randomstr(void)
{
	int	i;
	char	*random = (char *)malloc(sizeof(*random) * 21);

	i = 0;
	while (i < 20)
		random[i++] = rand() % 128;
	random[i] = '\0';
	return (random);
}

int		main(void)
{
	int		i;
	int		out;
	int		ret1;
	int		ret2;
	int		ret3;
	int		pfd[2][2];
	char	buffer[3][21];
	char	zero[21] = " Fucker !";
	char	random;
	char	cat[200] = "Bonjour ";
	char	cat2[200] = "Bonjour ";
	char	*random1 = NULL;
	char	*random2 = NULL;
	char	*random3 = NULL;
	char	*random4 = NULL;
	char	*str1 = "Bonjour fucker.";
	char	*str2 = "fucker";

	srand(time(NULL));
	i = -1;
	puts("\033[31mPart 1:\033[0m");
	ft_bzero(zero, 3);
	while (++i < 3)
	{
		if (zero[i] != '\0')
		{
			puts("ft_bzero: \033[31mNot OK\033[0m");
			break ;
		}
	}
	if (i == 3)
		puts("ft_bzero: \033[32mOK\033[0m");
	random1 = randomstr();
	strcat(cat2, random1);
	ft_strcat(cat, random1);
	if (strcmp(cat, cat2))
		puts("ft_strcat: \033[31mNot OK\033[0m");
	else
		puts("ft_strcat: \033[32mOK\033[0m");
	free(random1);
	i = -2;
	while (++i < 128)
	{
		if (ft_isalpha(i) != isalpha(i))
		{
			puts("ft_isalpha: \033[31mNot OK\033[0m");
			break ;
		}
	}
	if (i == 128)
		puts("ft_isalpha: \033[32mOK\033[0m");
	i = -2;
	while (++i < 128)
	{
		if (ft_isdigit(i) != isdigit(i))
		{
			puts("ft_isdigit: \033[31mNot OK\033[0m");
			break ;
		}
	}
	if (i == 128)
		puts("ft_isdigit: \033[32mOK\033[0m");
	i = -2;
	while (++i < 128)
	{
		if (ft_isalnum(i) != isalnum(i))
		{
			puts("ft_isalnum: \033[31mNot OK\033[0m");
			break ;
		}
	}
	if (i == 128)
		puts("ft_isalnum: \033[32mOK\033[0m");
	i = -2;
	while (++i < 128)
	{
		if (ft_isascii(i) != isascii(i))
		{
			puts("ft_isascii: \033[31mNot OK\033[0m");
			break ;
		}
	}
	if (i == 128)
		puts("ft_isascii: \033[32mOK\033[0m");
	i = -2;
	while (++i < 128)
	{
		if (ft_isprint(i) != isprint(i))
		{
			puts("ft_isprint: \033[31mNot OK\033[0m");
			break ;
		}
	}
	if (i == 128)
		puts("ft_isprint: \033[32mOK\033[0m");
	random1 = randomstr();
	random2 = strdup(random1);
	i = -2;
	while (random1[++i])
	{
		random1[i] = ft_toupper(random1[i]);
		random2[i] = toupper(random2[i]);
	}
	if (strcmp(cat, cat2))
		puts("ft_toupper: \033[31mNot OK\033[0m");
	else
		puts("ft_toupper: \033[32mOK\033[0m");
	//	free(random1);
	//	free(random2);
	//	random1 = randomstr();
	//	random2 = strdup(random1);
	i = -2;
	while (random1[++i])
	{
		random1[i] = ft_tolower(random1[i]);
		random2[i] = tolower(random2[i]);
	}
	if (strcmp(cat, cat2))
		puts("ft_tolower: \033[31mNot OK\033[0m");
	else
		puts("ft_tolower: \033[32mOK\033[0m");
	//	free(random1);
	//	del(&random1);
	//	free(random2);
	//	random1 = randomstr();
	bzero(buffer[0], 21);
	bzero(buffer[1], 21);
	out = dup(1);		// duplicate stdout fd to out
	pipe(pfd[0]);
	dup2(pfd[0][1], 1);
	ret1 = puts(random1);
	dup2(out, 1);
	read(pfd[0][0], buffer[0], 21);
	buffer[0][20] = '\0';
	close(pfd[0][0]);
	close(pfd[0][1]);
	out = dup(1);		// duplicate stdout fd to out
	pipe(pfd[1]);
	dup2(pfd[1][1], 1);
	ret2 = ft_puts(random1);
	dup2(out, 1);
	read(pfd[1][0], buffer[1], 21);
	buffer[1][20] = '\0';
	close(pfd[1][0]);
	close(pfd[1][1]);
	if (ret1 != ret2)
	{
		puts("ft_puts(random string): \033[31mNot OK\033[0m");
		printf("puts = %d\n, ft_puts = %d\n", ret1, ret2);
	}
	if (!strcmp(buffer[0], buffer[1]))
		puts("ft_puts (random string): \033[32mOK\033[0m");
	else
		puts("ft_puts(random string): \033[31mNot OK\033[0m");
	bzero(buffer[2], 21);
	out = dup(1);		// duplicate stdout fd to out
	pipe(pfd[1]);
	dup2(pfd[1][1], 1);
	ft_puts(NULL);
	dup2(out, 1);
	read(pfd[1][0], buffer[2], 21);
	buffer[2][20] = '\0';
	close(pfd[1][0]);
	close(pfd[1][1]);
	if (!strcmp(buffer[2], "(null)\n"))
		puts("ft_puts (null pointer): \033[32mOK\033[0m");
	else
		puts("ft_puts(null pointer): \033[31mNot OK\033[0m");
	puts("\033[31mPart 2:\033[0m");
	if (ft_strlen(random1) != strlen(random1))
		puts("ft_strlen: \033[31mNot OK\033[0m");
	else
	{
		if (ft_strlen(NULL) != 0)
			puts("ft_strlen: \033[31mNot OK\033[0m");
		else
			puts("ft_strlen: \033[32mOK\033[0m");
	}
	//	free(random1);
	//	random1 = (char *)malloc(sizeof(char) * 21);
	bzero(random1, 21);
	//	random2 = (char *)malloc(sizeof(char) * 21);
	bzero(random2, 21);
	random = rand() % 128;
	memset(random1, random, 21);
	ft_memset(random2, random, 21);
	i = -1;
	while (++i < 21)
	{
		if (random1[i] != random2[i])
			break ;
	}
	if (i == 21)
		puts("ft_memset: \033[32mOK\033[0m");
	else
		puts("ft_memset: \033[31mNot OK\033[0m");
	//	if (memcmp_assert(random1, random2, 21))
	//		puts("ft_memset: \033[31mNot OK\033[0m");
	//	else
	//		puts("ft_memset: \033[32mOK\033[0m");
	//	free(random1);
	//	free(random2);
	//	random1 = (char *)malloc(sizeof(char) * 21);
	bzero(random1, 21);
	//	random2 = (char *)malloc(sizeof(char) * 21);
	bzero(random2, 21);
	//	random3 = (char *)malloc(sizeof(char) * 21);
	//	bzero(random3, 21);
	//	random4 = (char *)malloc(sizeof(char) * 21);
	//	bzero(random4, 21);
	random1 = randomstr();
	//	random3 = memcpy(random3, random1, 21);
	random2 = ft_memcpy(random2, random1, strlen(random1));
	//	random4 = memcpy(random4, random3, 21);
	if (memcmp(random2, random1, 21))
		puts("ft_memcpy: \033[31mNot OK\033[0m");
	else
		puts("ft_memcpy: \033[32mOK\033[0m");
	//	free(random3);
	//	free(random4);
	//	del(&random2);
	bzero(random2, 21);
	random2 = ft_strdup(random1);
	//	if (memcmp_assert(random2, random1, strlen(random1)))
	if (strcmp(random2, random1))
		puts("ft_strdup: \033[31mNot OK\033[0m");
	else
		puts("ft_strdup: \033[32mOK\033[0m");
	//	free(random1);
	//	free(random2);
	//	bzero(random1, 21);
	bzero(random2, 21);
	puts("\033[31mPart 3: See the provided shell script\033[0m");
	ft_cat(-1);
	ft_cat(42);
	puts("Displaying the content of the above-mentioned script\n");
	out = open("test_ft_cat.sh", O_RDONLY);
	ft_cat(out);
	close(out);
	puts("");
	puts("ft_cat, basic tests: \033[32mOK\033[0m");
	puts("ft_cat is waiting on stdin, type CTRL+D to continue");
	ft_cat(0);
	puts("\033[31mBonus part:\033[0m");
	i = -2;
	while (++i < 128)
	{
		if (ft_isblank(i) != isblank(i))
			break ;
	}
	if (i == 128)
		puts("ft_isblank: \033[32mOK\033[0m");
	else
		puts("ft_isblank: \033[31mNot OK\033[0m");
	i = -2;
	while (++i < 128)
	{
		if (ft_isspace(i) != isspace(i))
			break ;
	}
	if (i == 128)
		puts("ft_isspace: \033[32mOK\033[0m");
	else
		puts("ft_isspace: \033[31mNot OK\033[0m");
	//	random1 = randomstr();
	//	random2 = (char *)malloc(sizeof(*random2) * (strlen(random1) + 1));
	bzero(random2, 21);
	random2 = ft_strcpy(random2, random1);
	if (strcmp(random1, random2))
		puts("ft_strcpy: \033[31mNot OK\033[0m");
	else
		puts("ft_strcpy: \033[32mOK\033[0m");
	bzero(random2, 21);
	random2 = ft_strncpy(random2, random1, strlen(random1) / 2);
	if (strncmp(random1, random2, strlen(random1) / 2))
		puts("ft_strncpy: \033[31mNot OK\033[0m");
	else
		puts("ft_strncpy: \033[32mOK\033[0m");
	//	del(&random2);
	i = -1;
	random2 = ft_strnew(20);
	while (++i < 21)
	{
		if (random2[i] != 0)
			break ;
	}
	if (i != 21)
		puts("ft_strnew: \033[31mNot OK\033[0m");
	//	free(random2);
	random2 = ft_strnew(0);
	if (!random2 || (random2[0] != '\0'))
		puts("ft_strnew: \033[31mNot OK\033[0m");
	else
		puts("ft_strnew: \033[32mOK\033[0m");
	//	free(random2);
	random2 = ft_strnew(20);
	ft_memset(random2, 'B', 20);
	random2[10] = 'A';
	random3 = ft_memchr(random2, 'A', 21);
	random4 = memchr(random2, 'A', 21);
	if (random3 != random4)
		puts("ft_memchr: \033[31mNot OK\033[0m");
	random4 = NULL;
	random4 = ft_memchr(random2, 'C', 21);
	if (random4 != NULL)
		puts("ft_memchr: \033[31mNot OK\033[0m");
	else
		puts("ft_memchr: \033[32mOK\033[0m");
	random3 = ft_strchr(random2, 'A');
	random4 = strchr(random2, 'A');
	if (random3 != random4)
		puts("ft_strchr: \033[31mNot OK\033[0m");
	random4 = NULL;
	random4 = ft_strchr(random2, 'C');
	if (random4 != NULL)
		puts("ft_strchr: \033[31mNot OK\033[0m");
	else
		puts("ft_strchr: \033[32mOK\033[0m");
	random3 = NULL;
	random4 = NULL;
	//	free(random1);
	//	free(random2);
	//	random1 = ft_strdup("Caca boudin");
	random1 = randomstr();
//	random1 = "Cacas";
//	random2 = "Caca";
	random3 = random1;
	//	random2 = ft_strdup("Cacas boudins");;
	random2 = randomstr();
	ret1 = memcmp(random1, random3, strlen(random1));
	ret2 = ft_memcmp(random1, random3, strlen(random1));
	ret3 = my_memcmp(random1, random3, strlen(random1));
//	printf("random3 = %s\n", random3);
	if (ret1 != ret2)
		puts("ft_memcmp: \033[31mNot OK\033[0m");
	ret1 = memcmp(random1, random2, strlen(random1));
	ret2 = ft_memcmp(random1, random2, strlen(random1));
	ret3 = my_memcmp(random1, random2, strlen(random1));
	if (ret1 != ret2)
	{
		puts("ft_memcmp: \033[31mNot OK\033[0m");
		printf("ft_memcmp = %d\nmy_memcmp = %d\nmemcmp = %d\n", ret2, ret3, ret1);
	}
	else
		puts("ft_memcmp: \033[32mOK\033[0m");
	if (ft_strcmp(random1, random3) != strcmp(random1, random3))
		puts("ft_strcmp: \033[31mNot OK\033[0m");
	if (ft_strcmp(random1, random2) != strcmp(random1, random2))
	{
		puts("ft_strcmp: \033[31mNot OK\033[0m");
		printf("ft_strcmp = %d\nstrcmp = %d\n", ft_strcmp(random1, random2), strcmp(random1, random2));
	}
	else
		puts("ft_strcmp: \033[32mOK\033[0m");
	if (ft_strequ(random1, random3) != my_strequ(random1, random3))
		puts("ft_strequ: \033[31mNot OK\033[0m");
	if (ft_strequ(random1, random2) != my_strequ(random1, random2))
	{
		puts("ft_strequ: \033[31mNot OK\033[0m");
		printf("ft_strequ = %d\nmy_strequ = %d\n", ft_strequ(random1, random2), my_strequ(random1, random2));
	}
	else
		puts("ft_strequ: \033[32mOK\033[0m");
	ret1 = strncmp(random1, random3, 12);
	ret2 = ft_strncmp(random1, random3, 12);
	if (ret1 != ret2)
		puts("ft_strncmp: \033[31mNot OK\033[0m");
	ret1 = strncmp(random1, random2, 12);
	ret2 = ft_strncmp(random1, random2, 12);
	if (ret1 != ret2)
	{
		puts("ft_strncmp: \033[31mNot OK\033[0m");
		printf("ft_strncmp = %d\nstrncmp = %d\n", ret2, ret1);
	}
	else
		puts("ft_strncmp: \033[32mOK\033[0m");
	ret1 = my_strnequ(random1, random3, strlen(random1));
	ret2 = ft_strnequ(random1, random3, strlen(random1));
	if (ret1 != ret2)
		puts("ft_strnequ: \033[31mNot OK\033[0m");
	ret1 = my_strnequ(random1, random2, strlen(random1));
	ret2 = ft_strnequ(random1, random2, strlen(random1));
	if (ret1 != ret2)
	{
		puts("ft_strnequ: \033[31mNot OK\033[0m");
		printf("ft_strnequ = %d\nmy_strnequ = %d\n", ret2, ret1);
		ret1 = strncmp(random1, random2, 12);
		ret2 = ft_strncmp(random1, random2, 12);
		printf("ft_strncmp = %d\nstrncmp = %d\n", ret2, ret1);
	}
	else
		puts("ft_strnequ: \033[32mOK\033[0m");
	bzero(buffer[0], 21);
	bzero(buffer[1], 21);
	out = dup(1);		// duplicate stdout fd to out
	pipe(pfd[0]);
	dup2(pfd[0][1], 1);
	ft_striter(random1, &my_putstr);
	dup2(out, 1);
	read(pfd[0][0], buffer[0], 21);
	buffer[0][20] = '\0';
	close(pfd[0][0]);
	close(pfd[0][1]);
	out = dup(1);		// duplicate stdout fd to out
	pipe(pfd[1]);
	dup2(pfd[1][1], 1);
	my_striter(random1, &my_putstr);
	dup2(out, 1);
	read(pfd[1][0], buffer[1], 21);
	buffer[1][20] = '\0';
	close(pfd[1][0]);
	close(pfd[1][1]);
	if (!strcmp(buffer[0], buffer[1]))
		puts("ft_striter: \033[32mOK\033[0m");
	else
		puts("ft_striter: \033[31mNot OK\033[0m");
	bzero(buffer[0], 21);
	bzero(buffer[1], 21);
	out = dup(1);		// duplicate stdout fd to out
	pipe(pfd[0]);
	dup2(pfd[0][1], 1);
	ft_striteri(random1, &my_ppstr);
	dup2(out, 1);
	read(pfd[0][0], buffer[0], 21);
	buffer[0][20] = '\0';
	close(pfd[0][0]);
	close(pfd[0][1]);
	out = dup(1);		// duplicate stdout fd to out
	pipe(pfd[1]);
	dup2(pfd[1][1], 1);
	my_striteri(random1, &my_ppstr);
	dup2(out, 1);
	read(pfd[1][0], buffer[1], 21);
	buffer[1][20] = '\0';
	close(pfd[1][0]);
	close(pfd[1][1]);
	if (!strcmp(buffer[0], buffer[1]))
		puts("ft_striteri: \033[32mOK\033[0m");
	else
		puts("ft_striteri: \033[31mNot OK\033[0m");
	if (strcmp(ft_strstr(str1, ""), strstr(str1, "")) != 0)
		puts("ft_strstr: \033[31mNot OK\033[0m");
	if (strcmp(ft_strstr(str1, str2), strstr(str1, str2)) != 0)
	{
		puts("ft_strstr: \033[31mNot OK\033[0m");
		printf("ft_strstr = \"%s\"\n", ft_strstr(str1, str2));
		printf("strstr = \"%s\"\n", strstr(str1, str2));
	}
	else
		puts("ft_strstr: \033[32mOK\033[0m");
	return (0);
}
