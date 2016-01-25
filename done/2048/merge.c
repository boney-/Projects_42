/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:12:15 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 21:55:43 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	merge_up(int tab[4], t_env *e)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i < 3 && tab[i] == tab[i + 1])
		{
			tab[i] *= 2;
			e->score += tab[i];
			tab[i + 1] = 0;
		}
		i++;
	}
}

void	merge_down(int tab[4], t_env *e)
{
	int	i;

	i = 3;
	while (i >= 0)
	{
		if (i >= 1 && tab[i] == tab[i - 1])
		{
			tab[i] *= 2;
			e->score += tab[i];
			tab[i - 1] = 0;
		}
		i--;
	}
}

void	merge_left(int tab[4][4], t_env *e)
{
	int i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (i < 4 && tab[i][j] == tab[i + 1][j])
			{
				tab[i][j] *= 2;
				e->score += tab[i][j];
				tab[i + 1][j] = 0;
			}
			i++;
		}
		j++;
	}
}

void	merge_right(int tab[4][4], t_env *e)
{
	int i;
	int	j;

	j = 3;
	while (j >= 0)
	{
		i = 3;
		while (i >= 0)
		{
			if (i > 0 && tab[i][j] == tab[i - 1][j])
			{
				tab[i][j] *= 2;
				e->score += tab[i][j];
				tab[i - 1][j] = 0;
			}
			i--;
		}
		j--;
	}
}
