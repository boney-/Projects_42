/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:44:27 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/06 17:46:13 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	del_screen(void)
{
	puts_cmd("ho");
	puts_cmd("cd");
}

void	print_list(t_env *e)
{
	int	i;

	i = 0;
	del_screen();
	if (e->args)
	{
		e->sw = 0;
		while (e->args->next != e->start)
		{
			puts_str(e->args, i, e);
			e->args = e->args->next;
			i++;
		}
		puts_str(e->args, i, e);
	}
	e->args = e->start;
	e->sw = 0;
	puts_cmd("ho");
}
