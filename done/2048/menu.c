/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:18:22 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 22:03:54 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game.h"

static void	credits(t_env *e)
{
	WINDOW *credits;

	credits = newwin(10, 30, e->maxx / 2 - 5, e->maxy / 2 - 15);
	box(credits, 0, 0);
	mvwprintw(credits, 1, 2, "RUSH WONG KAR-WAI!");
	mvwprintw(credits, 3, 2, "Hhuang & jbonnet");
	mvwprintw(credits, 5, 2, "Adressez vos dons a");
	mvwprintw(credits, 6, 2, "jbonnet@student.42.fr");
	mvwprintw(credits, 7, 2, "(uniquement)");
	wgetch(credits);
}

int			select_menu(int tab[4][4], t_env *e, int n)
{
	if (e->lose == 1 && n == '1')
		init_game(tab, e);
	else if (e->lose == 1 && n == '2')
		credits(e);
	if (e->win && n == '1')
	{
		e->win = 2;
		redraw_screen(tab, e);
	}
	else if (e->win && n == '2')
		init_game(tab, e);
	else if (n == '3')
		n = 27;
	return (n);
}
