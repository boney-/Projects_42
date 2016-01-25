/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 16:26:08 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/05 19:24:22 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <termios.h>
# include <curses.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>

typedef struct		s_listd
{
	char			*content;
	char			select;
	char			cursor;
	struct s_listd	*prev;
	struct s_listd	*next;
}					t_listd;

typedef struct		s_env
{
	char			*name_term;
	struct termios	term;
	struct termios	default_term;
	t_listd			*args;
	t_listd			*start;
	int				sw;
	int				oldsize;
}					t_env;
void				tab_to_lst(t_listd **list, char **args, t_env *e);
int					get_max_element_size(t_env *e);
void				puts_str(t_listd *list, int i, t_env *e);
void				move_cursor(char c, t_env *e);
void				select_current(t_env *e);
int					callc(int c);
void				print_list(t_env *e);
int					puts_cmd(char *cmd);
int					exit_prop(t_env *e);
int					get_winsize(int n);
int					buff_read(t_env *e);
void				sig_stop(int a);
void				sig_cont(int a);
void				reprint(int a);
int					count_param(t_env *e);
int					size_lst(t_env *e);
int					ft_init(t_env *e);
void				delete_this(t_env *e);
int					print_out(t_env *e);
#endif
