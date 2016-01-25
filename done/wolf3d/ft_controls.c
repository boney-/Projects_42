/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 13:08:54 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/06 17:28:38 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_move_right(t_env *e)
{
	e->old_dirx = e->dirx;
	e->dirx = e->dirx * cos(-(e->rotspeed)) - e->diry *
		sin(-(e->rotspeed));
	e->diry = e->old_dirx * sin(-(e->rotspeed)) + e->diry *
		cos(-(e->rotspeed));
	e->old_planex = e->planex;
	e->planex = e->planex * cos(-(e->rotspeed)) - e->planey *
		sin(-(e->rotspeed));
	e->planey = e->old_planex * sin(-(e->rotspeed)) + e->planey *
		cos(-(e->rotspeed));
}

void	ft_move_left(t_env *e)
{
	e->old_dirx = e->dirx;
	e->dirx = e->dirx * cos(e->rotspeed) - e->diry *
		sin(e->rotspeed);
	e->diry = e->old_dirx * sin(e->rotspeed) + e->diry *
		cos(e->rotspeed);
	e->old_planex = e->planex;
	e->planex = e->planex * cos(e->rotspeed) - e->planey *
		sin(e->rotspeed);
	e->planey = e->old_planex * sin(e->rotspeed) + e->planey *
		cos(e->rotspeed);
}

void	ft_change_pos(t_env *e)
{
	if (e->up)
	{
		if (e->map[(int)(e->posx + e->dirx * e->movespeed)]
				[(int)(e->posy)] == 0)
			e->posx += e->dirx * e->movespeed;
		if (e->map[(int)(e->posx)][(int)(e->posy + e->diry *
					e->movespeed)] == 0)
			e->posy += e->diry * e->movespeed;
	}
	if (e->down)
	{
		if (e->map[(int)(e->posx - e->dirx * e->movespeed)]
				[(int)(e->posy)] == 0)
			e->posx -= e->dirx * e->movespeed;
		if (e->map[(int)(e->posx)][(int)(e->posy - e->diry *
					e->movespeed)] == 0)
			e->posy -= e->diry * e->movespeed;
	}
	if (e->right)
		ft_move_right(e);
	if (e->left)
		ft_move_left(e);
}
