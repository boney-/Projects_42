/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:25:21 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/17 16:39:17 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "sh1.h"

void	ft_tab_to_lst(t_list **list, char **tab)
{
	int		i;
	t_list	*new;

	i = 0;
	while (tab[i])
	{
		new = ft_lstnew(tab[i], ft_strlen(tab[i]) + 1);
		ft_lstpush(list, new);
		i++;
	}
}

int		ft_strchar(char *str, unsigned char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	else
		return (0);
}

void	ft_err(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
}
