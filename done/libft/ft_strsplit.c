/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:26:28 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/19 16:50:46 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_wordcount(char const *s, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
			j++;
		}
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
	}
	return (j);
}

static	char	**ft_tabfiller(char const *s, char c, char **tab, int tabnb)
{
	int			i;
	int			j;
	int			n;
	int			index;

	n = 0;
	j = 0;
	index = 0;
	while ((s[index] != '\0') && (n < tabnb))
	{
		while ((s[index] == c) && (s[index] != '\0'))
			index++;
		i = index;
		if ((s[index] != c) && (s[index] != '\0'))
		{
			while ((s[index] != c) && (s[index] != '\0'))
				index++;
			j = index;
			tab[n] = ft_strsub(s, i, (j - i));
			n++;
		}
	}
	tab[n] = '\0';
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int			tabnb;
	char		**tab;

	if (s == NULL)
		return (NULL);
	tab = NULL;
	tabnb = ft_wordcount(s, c);
	if ((tab = (char **)malloc((sizeof(char *) * tabnb) + 1)) == NULL)
		return (NULL);
	tab = ft_tabfiller(s, c, tab, tabnb);
	return (tab);
}
