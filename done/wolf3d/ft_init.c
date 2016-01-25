/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 13:16:15 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/06 17:34:29 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_e(t_env *e)
{
	e->up = 0;
	e->down = 0;
	e->right = 0;
	e->left = 0;
	e->posx = 22;
	e->posy = 14;
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->time = 0;
	e->anim = 0;
	e->options = 0;
	e->oldtime = 0;
	e->movespeed = 0.04;
	e->rotspeed = 0.05;
	e->menu = 1;
}

void	ft_init_map(t_env *e)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	buff = NULL;
	e->map = (int**)malloc(sizeof(int*) * MAPH);
	fd = open("./misc/map/map.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Map not found", 2);
		return ;
	}
	while (get_next_line(fd, &buff) == 1)
	{
		e->map[i] = ft_strsplittoint(buff, ' ');
		free(buff);
		i++;
	}
	close(fd);
}
