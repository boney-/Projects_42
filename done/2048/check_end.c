/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:27:03 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 21:55:59 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			check_win(int tab[4][4])
{
	int		i;
	int		j;
	int		win_value;

	i = 0;
	j = 0;
	check_win_value(&win_value);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == win_value)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			check_lose(int tab[4][4], int i, int j)
{
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			if (tab[i][j] == tab[i][j + 1])
				return (0);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 3)
		{
			if (tab[i][j] == tab[i + 1][j])
				return (0);
			i++;
		}
		j++;
	}
	return ((count_zero(tab) == 0 ? 1 : 0));
}

void		check_end(int tab[4][4], t_env *e)
{
	if (check_lose(tab, 0, 0))
		e->lose = 1;
	else if (check_win(tab) && e->win == 0)
		e->win = 1;
}
