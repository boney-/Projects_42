/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_up_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:50:42 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 19:31:08 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_up_convs(char c, t_env *e)
{
	if (c == 'h')
		e->h += 1;
	if (c == 'l' || c == 'D' || c == 'j' || c == 'z')
		e->l += 1;
	if (c == 'x')
		e->x = 1;
	if (c == 'o')
		e->o = 1;
	if (c == 'O')
		e->go = 1;
	if (c == 'u')
		e->u = 1;
	if (c == 'U')
		e->gu = 1;
	if (c == 'X')
		e->gx = 1;
}

void	ft_up_flags(char *flags, int i, t_env *e)
{
	while (flags[i])
	{
		if (flags[i] == '-')
			e->moins = 1;
		if (flags[i] == ' ')
			e->space = 1;
		if (flags[i] == '+')
			e->plus = 1;
		if (flags[i] == '#')
			e->diez = 1;
		ft_up_convs(flags[i], e);
		i++;
	}
}
