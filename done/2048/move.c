/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:11:08 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 21:55:48 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_up(int tab[4])
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < 4)
	{
		if (tab[i] == 0)
		{
			y = i;
			while (tab[y] == 0 && y < 4)
				y++;
			if (y >= 4)
				break ;
			tab[i] = tab[y];
			tab[y] = 0;
		}
		i++;
	}
}

void	move_down(int tab[4])
{
	int i;
	int y;

	i = 3;
	y = 0;
	while (i >= 0)
	{
		if (tab[i] == 0)
		{
			y = i;
			while (tab[y] == 0 && y < 4)
				y--;
			if (y < 0)
				break ;
			tab[i] = tab[y];
			tab[y] = 0;
		}
		i--;
	}
}

void	move_left(int tab[4][4])
{
	int i;
	int j;
	int	k;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tab[i][j] == 0)
			{
				k = i;
				while (tab[k][j] == 0 && k < 4)
					k++;
				if (k > 3)
					break ;
				tab[i][j] = tab[k][j];
				tab[k][j] = 0;
			}
			i++;
		}
		j++;
	}
}

void	move_right(int tab[4][4])
{
	int i;
	int j;
	int	k;

	j = 3;
	while (j >= 0)
	{
		i = 3;
		while (i >= 0)
		{
			if (tab[i][j] == 0)
			{
				k = i;
				while (tab[k][j] == 0 && k >= 0)
					k--;
				if (k < 0)
					break ;
				tab[i][j] = tab[k][j];
				tab[k][j] = 0;
			}
			i--;
		}
		j--;
	}
}
