/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:49:35 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 19:31:55 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putwchar(int c, t_env *e)
{
	write(1, &c, 1);
	e->rvalue++;
}

void	ft_print_wchar(char *mask, t_env *e)
{
	char	**tab;
	int		i;
	int		j;
	int		mult;
	int		res;

	tab = ft_strsplit(mask, ' ');
	i = 0;
	while (tab[i])
	{
		res = 0;
		mult = 128;
		j = 0;
		while (tab[i][j])
		{
			res += (int)(tab[i][j++] - '0') * mult;
			mult /= 2;
		}
		ft_putwchar(res, e);
		i++;
	}
}

void	ft_fill_mask(char *maskk, char *str, int len, t_env *e)
{
	int		i;
	char	*mask;

	mask = ft_strdup(maskk);
	i = ft_strlen(mask) - 1;
	while (len >= 0)
	{
		if (mask[i] == 'x')
			mask[i] = str[len--];
		i--;
	}
	while (mask[i])
	{
		if (mask[i] == 'x')
			mask[i] = '0';
		i--;
	}
	ft_print_wchar(mask, e);
}
