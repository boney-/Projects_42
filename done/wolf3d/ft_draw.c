/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 13:11:16 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/06 17:30:48 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_pixput_to_image(unsigned int img_color,
		t_env *e, int x, int y)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	color1 = (img_color & 0xFF0000) >> 16;
	color2 = (img_color & 0xFF00) >> 8;
	color3 = (img_color & 0xFF) >> 0;
	e->table[y * e->size + x * e->bpp / 8] = color3;
	e->table[y * e->size + x * e->bpp / 8 + 1] = color2;
	e->table[y * e->size + x * e->bpp / 8 + 2] = color1;
}

void	ft_draw_ver_line(int x, int start, int end, t_env *e)
{
	int		i;

	i = 0;
	while (i < WIN_Y)
	{
		if (i > start + 2 && i < end - 2)
			ft_pixput_to_image(e->color, e, x, i);
		else if (i < start)
			ft_pixput_to_image(0x33CCCC, e, x, i);
		else if (i > end)
			ft_pixput_to_image(0x663300, e, x, i);
		else
			ft_pixput_to_image(0x000000, e, x, i);
		i++;
	}
}

void	ft_draw(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->table = mlx_get_data_addr(e->img, &e->bpp, &e->size, &e->endian);
	e->x = 0;
	while (e->x < WIN_X)
	{
		ft_calc_ray(e);
		ft_calc_step_side(e);
		ft_dda(e);
		ft_calc_dist_wall(e);
		ft_calc_line_height(e);
		ft_draw_ver_line(e->x, e->drawstart, e->drawend, e);
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_change_pos(e);
}

void	ft_options(t_env *e)
{
	int		width;
	int		height;

	width = 920;
	height = 600;
	if (e->up)
		e->menu = 1;
	if (e->down)
		e->menu = 2;
	if (e->menu == 1)
		e->img = mlx_xpm_file_to_image(e->mlx,
				"./misc/images/reprendre.xpm", &width, &height);
	else
		e->img = mlx_xpm_file_to_image(e->mlx,
				"./misc/images/exit.xpm", &width, &height);
	e->table = mlx_get_data_addr(e->img, &e->bpp, &e->size, &e->endian);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
