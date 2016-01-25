/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 19:12:28 by jbonnet           #+#    #+#             */
/*   Updated: 2016/01/02 17:19:38 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isprint(int c);
int		ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, char *s2);
char	*ft_memset(char *s1, int c, size_t n);
int		ft_puts(char *str);
char	*ft_strdup(char *s1);

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


int		main(int ac, char **av)
{
	int l1;
	int l2;
	char *str2 = randomstr();
	char *str1 = randomstr();
	char *str3 = randomstr();
	int i = -1;
	
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
	// MEMCPY TEST
	ft_memcpy(str3, str1, 21);
	if (memcmp(str1, str3, 21) == 0)
		puts("memcpy \033[32mOK!\033[0m");
	else
		puts("memcpy \033[31mK.O.\033[0m");

	return (0);
}
