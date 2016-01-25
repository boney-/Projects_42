/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 16:03:58 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/26 14:19:41 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		lstpush_mod(t_listd **list, t_listd *new, t_env *e)
{
	new->select = 0;
	if (*list == NULL)
	{
		*list = new;
		e->start = *list;
		(*list)->cursor = 1;
		(*list)->prev = *list;
		(*list)->next = *list;
	}
	else
	{
		new->prev = (*list)->prev;
		new->next = *list;
		(*list)->prev = new;
		while ((*list)->next != e->start)
			*list = (*list)->next;
		(*list)->next = new;
		*list = e->start;
	}
}

t_listd		*lstnew_mod(char *str)
{
	t_listd	*new;

	new = (t_listd *)malloc(sizeof(t_listd));
	if (new && str)
	{
		new->content = str;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

void		tab_to_lst(t_listd **list, char **args, t_env *e)
{
	t_listd *new;
	int		i;

	i = 1;
	while (args[i])
	{
		new = lstnew_mod(args[i]);
		lstpush_mod(list, new, e);
		i++;
	}
}
