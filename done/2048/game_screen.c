/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:20:18 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 22:01:20 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game.h"

int		lose_screen(t_env *e)
{
	WINDOW	*message;
	int		n;

	message = newwin(10, 30, e->maxx / 2 - 5, e->maxy / 2 - 15);
	box(message, 0, 0);
	refresh();
	mvwprintw(message, 1, 11, "GAME OVER");
	mvwprintw(message, 3, 8, "1 - New game");
	mvwprintw(message, 4, 8, "2 - Credits");
	mvwprintw(message, 5, 8, "3 - Exit");
	mvwprintw(message, 8, 3, "Final score: ");
	mvwprintw(message, 8, 16, ft_itoa(e->score));
	while (n != '1' && n != '2' && n != '3' && n != KEY_RESIZE)
		n = wgetch(message);
	delwin(message);
	return (n);
}

int		win_screen(t_env *e)
{
	WINDOW	*message;
	int		n;

	message = newwin(10, 30, e->maxx / 2 - 5, e->maxy / 2 - 15);
	box(message, 0, 0);
	refresh();
	mvwprintw(message, 1, 11, "YOU WIN!");
	mvwprintw(message, 3, 8, "1 - Continue");
	mvwprintw(message, 4, 8, "2 - New game");
	mvwprintw(message, 5, 8, "3 - Exit");
	mvwprintw(message, 8, 3, "Your score: ");
	mvwprintw(message, 8, 15, ft_itoa(e->score));
	while (n != '1' && n != '2' && n != '3' && n != KEY_RESIZE)
		n = wgetch(message);
	delwin(message);
	return (n);
}
