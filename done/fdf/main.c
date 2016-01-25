/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 17:08:24 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/28 15:48:47 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void	ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

void	ft_init_display_data(t_env *e)
{
	e->add_z = 1;
	e->add_scale = 1;
	e->add_x = 240;
	e->add_y = 95;
	e->move_unit = 10;
	e->list = NULL;
	e->proj = 0;
}

int		main(int ac, char **av)
{
	t_env	e;

	ft_init_display_data(&e);
	if (ac != 2)
		ft_error("Nombre d'argument incorrect.");
	ft_parse(av[1], &e.list);
	e.map_name = av[1];
	if (!(e.mlx = mlx_init()))
		ft_error("mlx_init: error.");
	if (!(e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "fdf")))
		ft_error("mlx_new_window: error.");
	if (!(e.img = mlx_new_image(e.mlx, IMG_X, IMG_Y)))
		ft_error("mlx_new_image: error.");
	if (!(e.table = mlx_get_data_addr(e.img, &e.bpp, &e.size, &e.endian)))
		ft_error("mlx_get_data_addr: error.");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
