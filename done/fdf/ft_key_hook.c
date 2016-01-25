/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 17:08:40 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/28 18:09:08 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "fdf.h"

#define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

int		ft_rcouleur(int z0, int z1)
{
	int green;
	int blue;

	green = 0;
	blue = 150;
	z0 = -z0;
	if (z0 > 0 || z1 > 0)
	{
		if (z0 > 255)
		{
			green = z0 - 255;
			blue = (green > 255 ? green - 255 : blue);
			green = (green > 255 ? 255 : green);
			if (blue > 255)
				return (RGB(255, 255, 255));
			z0 = 255;
		}
	}
	return (RGB(blue, green, z0));
}

int		couleur(int z0, int z1)
{
	int red;
	int blue;

	red = 0;
	blue = 150;
	if (z0 < 0)
		return (ft_rcouleur(z0, z1));
	if (z0 > 0 || z1 > 0)
	{
		if (z0 > 255)
		{
			red = z0 - 255;
			blue = (red > 255 ? red - 255 : blue);
			red = (red > 255 ? 255 : red);
			if (blue > 255)
				return (RGB(255, 255, 255));
			z0 = 255;
		}
	}
	return (RGB(blue, z0, red));
}

void	ft_treatcase(int keycode, t_env *e)
{
	if (keycode == 65363)
		e->add_scale++;
	if (keycode == 65361)
		e->add_scale--;
	if (keycode == 65362)
		e->add_z++;
	if (keycode == 65364)
		e->add_z--;
	if (keycode == 119)
		e->add_y -= e->move_unit;
	if (keycode == 115)
		e->add_y += e->move_unit;
	if (keycode == 97)
		e->add_x -= e->move_unit;
	if (keycode == 100)
		e->add_x += e->move_unit;
	if (keycode == 104)
		e->help = (e->help == 1 ? 0 : 1);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit (0);
	if (keycode == 32)
	{
		e->add_z = 1;
		e->add_scale = 0;
		e->add_x = (e->proj == 1 ? -420 : 240);
		e->add_y = (e->proj == 1 ? 25 : 95);
	}
	if (keycode == 49)
	{
		e->add_x = 240;
		e->add_y = 95;
		e->proj = 0;
	}
	if (keycode == 50)
	{
		e->add_x = -420;
		e->add_y = 25;
		e->proj = 1;
	}
	ft_treatcase(keycode, e);
	expose_hook(e);
	return (0);
}
