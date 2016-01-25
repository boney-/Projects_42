/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 20:43:48 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/12 15:53:27 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <time.h>
# include <pwd.h>
# include <unistd.h>
# include <grp.h>
# include "libft.h"

# define OPT_L	1
# define OPT_A	2
# define OPT_R	4
# define OPT_T	8
# define OPT_1 16

typedef struct	s_tab
{
	char mask;
	char option;
}				t_tab;

typedef struct	s_ls_max_len
{
	unsigned int		c1;
	unsigned int		c2;
	unsigned int		c3;
	unsigned int		c4;
}				t_ls_max_len;

int				ft_check_options(int nb, char **args);
void			ft_display_list(t_list *list, char *file);
void			ft_sort_lst(t_list **list, char *str,
			int (*f)(const char*, const char*, char *file), char *file);
void			ft_ls_max_length(t_list *list, t_ls_max_len *tab, char *file);
size_t			ft_cnt(int n);
void			ft_show_usr(struct stat *filestat, t_ls_max_len tab);
void			ft_show_perms(struct stat *filestat, t_ls_max_len tab);
int				ft_fill_from_dir(char *file);
int				ft_strcmp_ls(const char *s1, const char *s2, char *file);
int				ft_strtime_diff(const char *s1, const char *s2, char *file);
void			ft_print_space(int n);
char			*ft_add_slash(char *file);
void			ft_prez(char *file);
int				ft_check_illegal(char **av, int max);
int				ft_check_ill_options(char c);
#endif
