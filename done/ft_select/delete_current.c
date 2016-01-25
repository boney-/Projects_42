/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_current.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:57:04 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/26 14:19:48 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	delete_this(t_env *e)
{
	t_listd	*temp;

	if (size_lst(e) > 1)
	{
		while (e->args->next->cursor != 1)
			e->args = e->args->next;
		if (e->args->next == e->start)
			e->start = e->args->next->next;
		temp = e->args->next->next;
		e->args->next->next->prev = e->args;
		e->args->next = temp;
		e->args->cursor = 1;
		move_cursor('B', e);
	}
	else
		exit_prop(e);
}
