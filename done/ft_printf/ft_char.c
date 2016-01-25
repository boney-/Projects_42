/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:59:34 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 19:30:08 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_treat_char(char *flags, char c, t_env *e)
{
	ft_treat_options(flags, e);
	if (e->prespace && ft_atoi(e->precision[0]) > 1)
	{
		if (e->moins)
		{
			ft_putchar_mod(c, e);
			ft_print_char(ft_atoi(e->precision[0]) - 1, ' ', e);
		}
		else
		{
			ft_print_char(ft_atoi(e->precision[0]) - 1,
					(e->zero ? '0' : ' '), e);
			ft_putchar_mod(c, e);
		}
	}
	else
		ft_putchar_mod(c, e);
}
