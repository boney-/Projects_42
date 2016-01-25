/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 16:12:23 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/06 17:46:16 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF_H
# define FT_WOLF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <libft.h>
# include <unistd.h>
# include <get_next_line.h>
# include <X11/Xlib.h>
# include <sys/time.h>

# define MAPW 64
# define MAPH 64

typedef struct		s_env
{
	void			*mlx;
	char			*map_name;
	void			*img;
	void			*img_sky;
	void			*win;
	char			*table;
	int				**map;
	int				bpp;
	int				size;
	int				endian;
	int				x;
	double			posx;
	double			posy;
	double			dirx;
	double			old_dirx;
	double			diry;
	double			planex;
	double			old_planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
	int				up;
	int				down;
	int				right;
	int				left;
	double			movespeed;
	double			rotspeed;
	int				options;
	int				menu;
	int				anim;
}					t_env;

void				ft_pixput_to_image(unsigned int img_color,
		t_env *e, int x, int y);
void				ft_calc_step_side(t_env *e);
void				ft_calc_line_height(t_env *e);
void				ft_calc_dist_wall(t_env *e);
void				ft_dda(t_env *e);
void				ft_calc_ray(t_env *e);
void				ft_init_e(t_env *e);
void				ft_init_sky(t_env *e);
void				ft_draw_ver_line(int x, int start, int end, t_env *e);
void				ft_init_map(t_env *e);
void				ft_move_right(t_env *e);
void				ft_move_left(t_env *e);
void				ft_change_pos(t_env *e);
void				ft_draw(t_env *e);
void				ft_options(t_env *e);
int					ft_loop(t_env *e);
int					ft_key_hook(int keycode, t_env *e);
int					ft_key_hook_r(int keycode, t_env *e);

# define WIN_X 920
# define WIN_Y 600

#endif
