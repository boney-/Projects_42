/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 13:14:57 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/06 17:26:49 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_calc_step_side(t_env *e)
{
	if (e->raydirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rayposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->rayposx) * e->deltadistx;
	}
	if (e->raydiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rayposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->rayposy) * e->deltadisty;
	}
}

void	ft_calc_line_height(t_env *e)
{
	e->lineheight = abs((int)(WIN_Y / e->perpwalldist));
	e->drawstart = -e->lineheight / 2 + WIN_Y / 2;
	if (e->drawstart < 0)
		e->drawstart = 0;
	e->drawend = e->lineheight / 2 + WIN_Y / 2;
	if (e->drawend >= WIN_Y)
		e->drawend = WIN_Y - 1;
	if (e->side == 0 && e->raydirx > 0)
		e->color = 0x00FF00;
	else if (e->side == 0 && e->raydirx < 0)
		e->color = 0xFF0000;
	else if (e->side == 1 && e->raydiry > 0)
		e->color = 0xFFFF00;
	else
		e->color = 0x00FFFF;
}

void	ft_calc_dist_wall(t_env *e)
{
	if (e->side == 0)
		e->perpwalldist = fabs((e->mapx - e->rayposx +
					(1 - e->stepx) / 2) / e->raydirx);
	else
		e->perpwalldist = fabs((e->mapy - e->rayposy +
					(1 - e->stepy) / 2) / e->raydiry);
}

void	ft_dda(t_env *e)
{
	while (1)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		if (e->map[e->mapx][e->mapy] > 0)
			return ;
	}
}

void	ft_calc_ray(t_env *e)
{
	e->camerax = 2 * e->x / (double)WIN_X - 1;
	e->rayposx = e->posx;
	e->rayposy = e->posy;
	e->raydirx = e->dirx + e->planex * e->camerax;
	e->raydiry = e->diry + e->planey * e->camerax;
	e->mapx = (int)e->rayposx;
	e->mapy = (int)e->rayposy;
	e->deltadistx = sqrt(1 + (e->raydiry * e->raydiry) /
			(e->raydirx * e->raydirx));
	e->deltadisty = sqrt(1 + (e->raydirx * e->raydirx) /
			(e->raydiry * e->raydiry));
}
