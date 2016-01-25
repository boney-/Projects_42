/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 17:08:11 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/28 17:57:38 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>
#include "get_next_line.h"
#include "mlx.h"

void	ft_link_hor_pix(t_position pos, t_env e, t_list **list, unsigned int i)
{
	t_values	*values;

	values = (*list)->content;
	if (i + 1 < values->size)
		draw_on_img(pos, e);
}

void	ft_link_ver_pix(t_position pos, t_env e, t_list **list, int i)
{
	t_list		*temp;
	t_values	*values;

	if ((*list)->next)
	{
		temp = (*list)->next;
		values = temp->content;
		pos.y1 = values->y * (SCALE + e.add_scale) + POS_Y;
		pos.x1 = pos.x0;
		pos.z1 = values->tab[i] * e.add_z;
		draw_on_img(pos, e);
	}
}

void	ft_get_pos_and_draw(t_list **list, t_env e)
{
	unsigned int	i;
	t_position		pos;
	t_values		*values;

	while ((int)i >= 0)
	{
		i = 0;
		values = (*list)->content;
		while (i < values->size)
		{
			pos.x0 = i * (SCALE + e.add_scale) + POS_X;
			pos.y0 = values->y * (SCALE + e.add_scale) + POS_Y;
			pos.x1 = (i + 1) * (SCALE + e.add_scale) + POS_X;
			pos.y1 = pos.y0;
			pos.z0 = values->tab[i] * e.add_z;
			pos.z1 = values->tab[i + 1] * e.add_z;
			ft_link_hor_pix(pos, e, list, i);
			ft_link_ver_pix(pos, e, list, i);
			i++;
		}
		if (i >= values->size && (*list)->next != NULL)
			*list = (*list)->next;
		else
			i = -1;
	}
}

void	ft_display_help(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 50, 25, 0xFFFFFF,
			e->map_name);
	mlx_string_put(e->mlx, e->win, 50, WIN_Y - 75, 0xFFFFFF,
			"1,2      View");
	mlx_string_put(e->mlx, e->win, 50, WIN_Y - 30, 0xFFFFFF,
			"<- OR -> Zoom");
	mlx_string_put(e->mlx, e->win, 50, WIN_Y - 45, 0xFFFFFF,
			"Space    Reset");
	mlx_string_put(e->mlx, e->win, 50, WIN_Y - 60, 0xFFFFFF,
			"WASD     Move");
	mlx_string_put(e->mlx, e->win, 50, WIN_Y - 15, 0xFFFFFF,
			"Esc      Exit");
}

int		expose_hook(t_env *e)
{
	t_list *temp;

	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, IMG_X, IMG_Y);
	if (!e->list)
		ft_error("Erreur : carte incorrecte");
	temp = e->list;
	ft_get_pos_and_draw(&temp, *e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, WIN_X / 2 - 23, 20, 0xFFFFFF, "H FOR HELP");
	if (e->help == 1)
		ft_display_help(e);
	return (0);
}
