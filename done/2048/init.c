/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:16:18 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 22:02:08 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "game.h"

static void	fill_tab_zero(int tab[4][4])
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (i < 4)
	{
		y = 0;
		while (y < 4)
			tab[i][y++] = 0;
		i++;
	}
}

static void	init_pair_color(void)
{
	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_YELLOW);
	init_pair(4, COLOR_BLACK, COLOR_CYAN);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(7, COLOR_BLACK, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
}

void		init_game(int tab[4][4], t_env *e)
{
	curs_set(0);
	start_color();
	init_pair_color();
	noecho();
	if (e->win == 0)
		check_win_value(&e->win_value);
	e->score = 0;
	e->oldscore = 0;
	e->lose = 0;
	e->win = 0;
	fill_tab_zero(tab);
	srand(time(NULL) / 2);
	tab[rand() % 4][(rand() % 16) / 4] = (rand() % 2 ? 2 : 4);
	add_digit_tab(tab);
}
