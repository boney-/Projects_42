/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:56:39 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 20:52:40 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_space_precision(char *str, t_env *e)
{
	int		i;
	int		j;

	e->precision = (char**)malloc(sizeof(char**) * 3);
	e->precision[0] = "0";
	i = 0;
	j = 0;
	while (str[i] && (str[i] <= '0' || str[i] > '9') && str[i] != '.')
	{
		if (str[i++] == '0')
			e->zero = 1;
	}
	j = i;
	while ((str[j] && (str[j] >= '0' && str[j] <= '9')) || str[j] == '.')
		e->point = (str[j++] == '.' ? 1 : e->point);
	if (j == i)
		return ;
	e->prespace = 1;
	e->precision[0] = ft_strsub(str, i, j - i);
	if (e->point)
	{
		e->precision[0] = ft_strjoin("0", e->precision[0]);
		e->precision = ft_strsplit(e->precision[0], '.');
		e->precision[1] = ft_strjoin("0", e->precision[1]);
	}
}
