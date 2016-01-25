/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:55:27 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 19:33:30 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_justification(char *str, t_env *e)
{
	if (e->moins)
	{
		ft_putstr_mod(str, e);
		ft_print_char(ft_atoi(e->precision[0]) - ft_strlen(str), ' ', e);
	}
	else if (e->zero && (e->isint == 0 || e->point == 0))
	{
		ft_print_char(ft_atoi(e->precision[0]) - ft_strlen(str), '0', e);
		ft_putstr_mod(str, e);
	}
	else
	{
		ft_print_char(ft_atoi(e->precision[0]) - ft_strlen(str), ' ', e);
		ft_putstr_mod(str, e);
	}
}

void	ft_treat_options(char *flags, t_env *e)
{
	ft_space_precision(flags, e);
}
