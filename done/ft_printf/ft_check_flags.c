/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:57:11 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/04 16:32:59 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_flags(char c)
{
	char	*flags;

	flags = "#0-+ |*hljz123456789.";
	while (*flags)
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

int		ft_check_convs(char c, t_env *e)
{
	char	*convs;

	convs = "sSpdDioOuUxXcC%";
	while (*convs)
	{
		if (*convs == c)
		{
			e->new = 0;
			return (1);
		}
		convs++;
	}
	return (0);
}

int		ft_check_c(char c, t_env *e)
{
	if (ft_isprint(c))
	{
		e->new = 0;
		return (1);
	}
	return (0);
}
