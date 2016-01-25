/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:22:06 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 22:04:07 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game.h"

void	print_color(int i)
{
	if (i == 0)
		attron(COLOR_PAIR(6));
	else if (i == 2)
		attron(COLOR_PAIR(2));
	else if (i == 4)
		attron(COLOR_PAIR(3));
	else if (i == 8)
		attron(COLOR_PAIR(4));
	else if (i == 16)
		attron(COLOR_PAIR(5));
	else if (i == 32)
		attron(COLOR_PAIR(6));
	else if (i > 32)
		attron(COLOR_PAIR(1));
}

void	print_number(int x, int y, int num, t_env *e)
{
	int i;
	int j;

	i = x - e->maxx / 8;
	j = y - e->maxy / 8;
	while (i < x + e->maxx / 8)
	{
		j = y - e->maxy / 8;
		while (j < y + e->maxy / 8)
		{
			mvaddch(i, j++, ' ');
		}
		i++;
	}
	if (ft_strlen(ft_itoa(num)) >= 3)
		y--;
	mvaddstr(x, y, ft_itoa(num));
}

void	print_tab(int larg, int haut, int tab[4][4], t_env *e)
{
	int dlarg;
	int hlarg;
	int	i;
	int	y;

	i = 0;
	dlarg = larg / 8;
	larg = larg / 4;
	hlarg = haut / 8;
	haut = haut / 4;
	while (i < 4)
	{
		y = 0;
		while (y < 4)
		{
			print_color(tab[i][y]);
			if (tab[i][y] != 0)
				print_number(dlarg, hlarg, tab[i][y], e);
			dlarg += larg;
			y++;
		}
		dlarg = dlarg - larg * 4;
		hlarg += haut;
		i++;
	}
}
