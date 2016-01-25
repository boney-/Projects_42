/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 16:09:22 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/06 17:32:55 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_loop(t_env *e)
{
	if (e->img != NULL)
		mlx_destroy_image(e->mlx, e->img);
	if (e->options == 0)
		ft_draw(e);
	else if (e->options == 1)
		ft_options(e);
	return (1);
}

int		main(void)
{
	t_env	e;

	e.mlx = mlx_init();
	ft_init_map(&e);
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Wolf3d");
	ft_init_e(&e);
	mlx_hook(e.win, KeyPress, KeyPressMask, &ft_key_hook, &e);
	mlx_hook(e.win, KeyRelease, KeyReleaseMask, &ft_key_hook_r, &e);
	mlx_loop_hook(e.mlx, &ft_loop, &e);
	mlx_loop(e.mlx);
	return (0);
}
