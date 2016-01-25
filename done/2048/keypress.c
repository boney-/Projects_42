/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:14:38 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 22:02:28 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game.h"

static void	move_left_right(int tab[4][4], int c, t_env *e)
{
	if (c == KEY_LEFT)
	{
		move_left(tab);
		merge_left(tab, e);
		move_left(tab);
	}
	if (c == KEY_RIGHT)
	{
		move_right(tab);
		merge_right(tab, e);
		move_right(tab);
	}
}

void		keypress_up_down(int tab[4][4], int c, t_env *e)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (c == KEY_UP)
		{
			move_up(tab[i]);
			merge_up(tab[i], e);
			move_up(tab[i]);
		}
		else if (c == KEY_DOWN)
		{
			move_down(tab[i]);
			merge_down(tab[i], e);
			move_down(tab[i]);
		}
		else
		{
			move_left_right(tab, c, e);
			break ;
		}
		i++;
	}
	add_digit_tab(tab);
}
