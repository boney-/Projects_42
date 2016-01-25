/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 17:08:51 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/28 18:40:44 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <math.h>

void	ft_pixput_to_image(unsigned int img_color,
		t_env *e, int x, int y)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	color1 = (img_color & 0xFF0000) >> 16;
	color2 = (img_color & 0xFF00) >> 8;
	color3 = (img_color & 0xFF) >> 0;
	e->table[y * e->size + x * e->bpp / 8] = color1;
	e->table[y * e->size + x * e->bpp / 8 + 1] = color2;
	e->table[y * e->size + x * e->bpp / 8 + 2] = color3;
}

void	draw_line(t_position pos, t_draw d, t_env e)
{
	d.dx = abs(pos.x1 - pos.x0);
	d.sx = pos.x0 < pos.x1 ? 1 : -1;
	d.dy = abs(pos.y1 - pos.y0);
	d.sy = pos.y0 < pos.y1 ? 1 : -1;
	d.err = (d.dx > d.dy ? d.dx : -d.dy) / 2;
	while (1)
	{
		if ((pos.x0 > 0 && pos.y0 > 0 && pos.x0 < WIN_X && pos.y0 < WIN_Y) &&
			(pos.z0 = (pos.z0 < pos.z1 ? pos.z0 + 1 : pos.z0 - 1)) != 99999999)
			ft_pixput_to_image(couleur(pos.z0, pos.z1), &e, pos.x0, pos.y0);
		if (pos.x0 == pos.x1 && pos.y0 == pos.y1)
			break ;
		d.e2 = d.err;
		if (d.e2 > -d.dx)
		{
			d.err -= d.dy;
			pos.x0 += d.sx;
		}
		if (d.e2 < d.dy)
		{
			d.err += d.dx;
			pos.y0 += d.sy;
		}
	}
}

void	ft_iso(t_position *pos, t_env *e)
{
	int		save_x;

	save_x = pos->x0;
	pos->x0 = CST2 * pos->x0 - CST2 * pos->y0;
	pos->x0 += e->add_x;
	pos->y0 = -pos->z0 + CST2 / 2 * save_x + CST2 / 2 * pos->y0;
	pos->y0 += e->add_y;
	save_x = pos->x1;
	pos->x1 = CST2 * pos->x1 - CST2 * pos->y1;
	pos->x1 += e->add_x;
	pos->y1 = -pos->z1 + CST2 / 2 * save_x + CST2 / 2 * pos->y1;
	pos->y1 += e->add_y;
}

void	ft_para(t_position *pos, t_env *e)
{
	pos->z0 = pos->z0;
	pos->x0 = pos->x0 + CST1 * -pos->z0;
	pos->x0 += e->add_x;
	pos->y0 = pos->y0 + CST1 / 2 * -pos->z0;
	pos->y0 += e->add_y;
	pos->z1 = pos->z1;
	pos->x1 = pos->x1 + CST1 * -pos->z1;
	pos->x1 += e->add_x;
	pos->y1 = pos->y1 + CST1 / 2 * -pos->z1;
	pos->y1 += e->add_y;
}

void	draw_on_img(t_position pos, t_env e)
{
	t_draw	d;

	if (e.proj == 0)
		ft_iso(&pos, &e);
	if (e.proj == 1)
		ft_para(&pos, &e);
	draw_line(pos, d, e);
}
