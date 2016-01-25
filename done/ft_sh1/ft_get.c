/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:19:09 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/18 15:46:15 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdlib.h>
#include "sh1.h"

void	ft_get_stdin(t_env *e)
{
	char	*line;
	char	**tab;
	int		i;

	i = 0;
	line = (char*)malloc(sizeof(char) * 250);
	ft_prompt();
	if (get_next_line(0, &line))
	{
		tab = ft_strsplit(line, ';');
		while (tab[i])
			ft_check_stdin(tab[i++], e);
		free(line);
	}
	else
		exit(0);
}

char	*ft_get_var_env(t_list **list, char *var)
{
	t_list	*temp;
	char	**tab;

	temp = *list;
	while (temp)
	{
		tab = ft_strsplit(temp->content, '=');
		if (ft_strcmp (tab[0], var) == 0)
			return (ft_strdup(tab[1]));
		temp = temp->next;
	}
	return (NULL);
}

char	*ft_get_first_word(char *str, char ***args)
{
	char	*word;
	int		i;

	i = 0;
	(void)args;
	while (str[i] && str[i] != ' ' && str[i] != ';' && str[i] != '\n')
		i++;
	word = ft_strsub(str, 0, i);
	*args = ft_strsplit(str, ' ');
	return (word);
}
