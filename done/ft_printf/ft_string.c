/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:59:22 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/04 17:05:32 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_treat_string(char *flags, char *str, t_env *e)
{
	ft_treat_options(flags, e);
	if (str == NULL)
		str = "(null)";
	if (e->prespace == 1)
	{
		if (e->point && e->precision[1] && !e->isint)
			ft_justification(ft_strsub(str, 0, ft_atoi(e->precision[1])), e);
		else
			ft_justification(str, e);
	}
	else
		ft_putstr_mod(str, e);
}
