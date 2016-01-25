/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:56:24 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/26 14:19:47 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		print_out(t_env *e)
{
	int	i;

	puts_cmd("te");
	i = count_param(e);
	while (i)
	{
		while (e->args->select == 0)
			e->args = e->args->next;
		ft_putstr(e->args->content);
		e->args = e->args->next;
		if (i > 1)
			ft_putchar(' ');
		i--;
	}
	exit_prop(e);
	return (1);
}
