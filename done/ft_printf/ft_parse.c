/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:44:23 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 20:50:38 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_parse(char *str, t_env *e)
{
	while (*str)
	{
		if (*str == '%')
		{
			ft_init(e);
			e->new = 1;
			str = (str + ft_check_str(str, e));
		}
		else
			ft_putchar_mod(*str, e);
		if (*str)
			str++;
	}
}

int		ft_check_str(char *str, t_env *e)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (ft_check_convs(str[i], e) || ft_check_flags(str[i]) ||
				ft_check_c(str[i], e))
		{
			if (e->new == 0)
			{
				ft_exec_arg(str, i, e);
				return (i);
			}
		}
		else
			return (i - 1);
		i++;
	}
	e->new = 0;
	return (i);
}
