/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:58:18 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 21:02:09 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar_mod(char c, t_env *e)
{
	write(1, &c, 1);
	e->rvalue++;
}

void	ft_putstr_mod(char *str, t_env *e)
{
	write(1, str, ft_strlen(str));
	e->rvalue = e->rvalue + ft_strlen(str);
}

void	ft_print_char(int i, char c, t_env *e)
{
	while (i > 0)
	{
		ft_putchar_mod(c, e);
		i--;
	}
}
