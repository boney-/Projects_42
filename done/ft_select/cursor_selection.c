/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:47:16 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/05 20:08:50 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	move_cursor(char c, t_env *e)
{
	while (e->args->cursor != 1)
		e->args = e->args->next;
	e->args->cursor = 0;
	if (c == 'A')
		e->args->prev->cursor = 1;
	else if (c == 'B')
		e->args->next->cursor = 1;
	e->args = e->start;
	print_list(e);
}

void	select_current(t_env *e)
{
	while (e->args->cursor != 1)
		e->args = e->args->next;
	e->args->select = (e->args->select ? 0 : 1);
	move_cursor('B', e);
}
