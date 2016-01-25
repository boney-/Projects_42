/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:12:34 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/01 22:05:14 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

#include <libft.h>

typedef struct	s_env
{
	int			maxx;
	int			maxy;
	int			lose;
	int			win;
	int			score;
	int			oldscore;
	int			win_value;
}				t_env;

enum e_const
{
	WIN_VALUE = 2048
};
void	add_digit_tab(int tab[4][4]);
void	check_end(int tab[4][4], t_env *e);
int		redraw_screen(int tab[4][4], t_env *e);
void	check_win_value(int *win_value);
int		digit_rand(int n);
void	init_game(int tab[4][4], t_env *e);
void    check_win_value(int *win_value);
int		select_menu(int tab[4][4], t_env *e, int n);
void	keypress_up_down(int tab[4][4], int c, t_env *e);
int		count_zero(int tab[4][4]);
void	print_tab(int larg, int haut, int tab[4][4], t_env *e);
int		lose_screen(t_env *e);
int		win_screen(t_env *e);
void	merge_down(int tab[4], t_env *e);
void	merge_left(int tab[4][4], t_env *e);
void	merge_right(int tab[4][4], t_env *e);
void	merge_up(int tab[4], t_env *e);
void	move_down(int tab[4]);
void	move_left(int tab[4][4]);
void	move_right(int tab[4][4]);
void	move_up(int tab[4]);
#endif
