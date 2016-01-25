/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_onelink.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:26:36 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/17 18:49:45 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_lstdel_onelink(t_env *e)
{
	t_list	*temp;
	t_list	*new;

	temp = e->list;
	new = temp;
	while (e->list)
	{
		if (ft_strequ((ft_strsplit(e->list->content, '='))[0], e->args[1]))
		{
			if (temp == e->list)
				temp = temp->next;
			if (e->list->next)
				new->next = e->list->next;
			else
				new->next = NULL;
			e->list = temp;
			return ;
		}
		new = e->list;
		e->list = e->list->next;
	}
	e->list = temp;
}
