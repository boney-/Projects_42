/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 12:20:17 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/19 12:20:23 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# define POS_Z
# define POS_X	500
# define POS_Y	20
# define WIN_X	1200
# define WIN_Y	1000
# define IMG_X	1200
# define IMG_Y	1000
# define SCALE	30
# define CST1	0.6
# define CST2	0.6
# include <libft.h>

typedef struct		s_values
{
	int				*tab;
	unsigned int	y;
	unsigned int	size;
}					t_values;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_list			*list;
	int				add_z;
	int				add_scale;
	int				add_x;
	int				add_y;
	int				move_unit;
	int				proj;
	char			*table;
	int				bpp;
	int				size;
	int				endian;
}					t_env;

typedef struct		s_position
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				z0;
	int				z1;
}					t_position;

typedef struct		s_draw
{
	int				dx;
	int				dy;
	int				err;
	int				e2;
	int				sx;
	int				sy;
}					t_draw;

int					key_hook(int keycode, t_env *e);
int					expose_hook(t_env *e);
void				draw_on_img(t_position pos, t_env e, unsigned long color);
int					*ft_parse(char *file, t_list **map);
#endif
