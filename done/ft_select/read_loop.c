/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:57:51 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/06 17:46:15 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	cursor_on_char(char *str, t_env *e)
{
	t_listd	*begin;
	int		i;

	i = 0;
	while (e->args->cursor != 1)
		e->args = e->args->next;
	begin = e->args;
	if (str[0] != e->args->content[0])
	{
		e->args = e->args->next;
		i++;
	}
	while (str[0] != e->args->content[0] && e->args != begin)
	{
		e->args = e->args->next;
		i++;
	}
	if (str[0] == e->args->content[0] && i > 0)
	{
		while (i > 0)
		{
			move_cursor('B', e);
			i--;
		}
	}
}

int		buff_read(t_env *e)
{
	char	buffer[3];

	while (1)
	{
		buffer[0] = '\0';
		buffer[1] = '\0';
		buffer[2] = '\0';
		read(0, buffer, 3);
		if (buffer[2] == 'A' || buffer[2] == 'B')
			move_cursor(buffer[2], e);
		else if (buffer[0] == ' ')
			select_current(e);
		else if (buffer[0] == 27 && buffer[1] == '\0')
			return (exit_prop(e));
		else if (buffer[0] == 127 && buffer[1] == '\0')
			delete_this(e);
		else if (buffer[0] == '\n')
			return (print_out(e));
		else if (buffer[0] != '\0')
			cursor_on_char(buffer, e);
	}
	return (0);
}
