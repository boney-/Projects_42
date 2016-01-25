/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:19:54 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 22:05:52 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "game.h"

int		count_zero(int tab[4][4])
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			if (tab[i][j++] == 0)
				k++;
		i++;
	}
	return (k);
}

void			add_digit_tab(int tab[4][4])
{
	int i;
	int	j;
	int	n;

	n = count_zero(tab);
	if (n == 0)
		return ;
	srand(time(NULL));
	n = rand() % n + 1;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (n <= 0 && tab[i][j] == 0)
			{
				tab[i][j] = digit_rand(n);
				return ;
			}
			n--;
			j++;
		}
		i++;
	}
}

void			check_win_value(int *win_value)
{
	int		value;

	value = WIN_VALUE;
	if (value)
	{
		while (value && value > 2 && !(value % 2))
			value /= 2;
		if (value == 2)
			*win_value = WIN_VALUE;
		else
			*win_value = 2048;
	}
	else
		*win_value = 2048;
}

int				main(void)
{
	WINDOW	*mainwin;
	t_env	e;
	int		n;
	int		tab[4][4];

	if ((mainwin = initscr()) == NULL)
		return (0);
	keypad(mainwin, TRUE);
	init_game(tab, &e);
	while (n != 27)
	{
		n = redraw_screen(tab, &e);
		n = (e.lose == 1 || e.win == 1 ? n : getch());
		if ((n == KEY_UP || n == KEY_DOWN || n == KEY_LEFT
					|| n == KEY_RIGHT) && e.lose == 0)
			keypress_up_down(tab, n, &e);
		else if (e.lose == 1 || e.win == 1)
			n = select_menu(tab, &e, n);
		clear();
		refresh();
	}
	delwin(mainwin);
	endwin();
	return (0);
}
