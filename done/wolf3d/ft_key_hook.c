/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 13:04:49 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/06 17:32:13 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == 65362 || keycode == 119)
		e->up = 1;
	if (keycode == 65364 || keycode == 115)
		e->down = 1;
	if (keycode == 65363 || keycode == 100)
		e->right = 1;
	if (keycode == 65361 || keycode == 97)
		e->left = 1;
	if (keycode == 65505 || keycode == 65506)
		e->movespeed = 0.08;
	if (keycode == 65289)
		e->options = 1;
	if (keycode == 65293 && e->options == 1)
	{
		if (e->menu == 2)
			exit(0);
		e->options = 0;
	}
	return (1);
}

int		ft_key_hook_r(int keycode, t_env *e)
{
	if (keycode == 65307)
	{
		if (e->options)
			e->options = 0;
		else
		{
			e->menu = 1;
			e->options = 1;
		}
	}
	if (keycode == 65289)
		e->options = 0;
	if (keycode == 65362 || keycode == 119)
		e->up = 0;
	if (keycode == 65364 || keycode == 115)
		e->down = 0;
	if (keycode == 65363 || keycode == 100)
		e->right = 0;
	if (keycode == 65361 || keycode == 97)
		e->left = 0;
	if (keycode == 65505 || keycode == 65506)
		e->movespeed = 0.04;
	return (1);
}
