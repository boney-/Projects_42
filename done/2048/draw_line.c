/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:13:48 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 21:59:10 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game.h"

static void	draw_horline(int larg, int haut)
{
	int		i;
	int		y;
	int		quot;

	i = 1;
	y = 0;
	quot = haut / 4;
	haut = quot;
	while (y < 3)
	{
		i = 1;
		while (i < larg - 1)
			mvaddch(i++, haut, ACS_VLINE);
		haut += quot;
		y++;
	}
}

static void	draw_verline(int larg, int haut)
{
	int		i;
	int		y;
	int		quot;

	i = 1;
	y = 0;
	attron(COLOR_PAIR(7));
	quot = larg / 4;
	larg = quot;
	while (y < 3)
	{
		i = 1;
		while (i < haut - 1)
			mvaddch(larg, i++, ACS_HLINE);
		larg += quot;
		y++;
	}
}

static void	print_score(t_env *e)
{
	attron(COLOR_PAIR(8));
	mvprintw(0, e->maxy - 20, "SCORE : ");
	mvprintw(0, e->maxy - 12, ft_itoa(e->score));
	mvprintw(0, e->maxy - 6, " +");
	mvprintw(0, e->maxy - 4, ft_itoa(e->score - e->oldscore));
	e->oldscore = e->score;
	attron(COLOR_PAIR(7));
}

int			redraw_screen(int tab[4][4], t_env *e)
{
	int n;

	n = 1;
	getmaxyx(stdscr, e->maxx, e->maxy);
	if (e->maxx > 15 && e->maxy > 30)
	{
		print_tab(e->maxx, e->maxy, tab, e);
		draw_verline(e->maxx, e->maxy);
		draw_horline(e->maxx, e->maxy);
		wborder(stdscr, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
				ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
		print_score(e);
		check_end(tab, e);
		if (e->lose == 1)
			n = lose_screen(e);
		else if (e->win == 1)
			n = win_screen(e);
	}
	else
	{
		attron(COLOR_PAIR(8));
		printw("Window's size too small.");
		attron(COLOR_PAIR(7));
	}
	return (n);
}
