/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perms_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 15:13:03 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/11 19:28:24 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

extern t_tab	g_tab_options[5];
extern char		g_opt;

void	ft_show_perms(struct stat *filestat, t_ls_max_len tab)
{
	if (S_ISDIR(filestat->st_mode))
		ft_putstr("d");
	else if (S_ISLNK(filestat->st_mode))
		ft_putstr("l");
	else
		ft_putstr("-");
	ft_putstr((filestat->st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((filestat->st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((filestat->st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((filestat->st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((filestat->st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((filestat->st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((filestat->st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((filestat->st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((filestat->st_mode & S_IXOTH) ? "x" : "-");
	ft_print_space(tab.c1 - ft_cnt(filestat->st_nlink));
	ft_putstr("  ");
	ft_putnbr(filestat->st_nlink);
	ft_show_usr(filestat, tab);
}

void	ft_show_usr(struct stat *filestat, t_ls_max_len tab)
{
	struct passwd	*usr;
	struct group	*grp;
	char			*mtime;

	mtime = ft_strnew(12);
	usr = getpwuid(filestat->st_uid);
	ft_putstr(" ");
	ft_putstr(usr->pw_name);
	ft_print_space(tab.c2 - ft_strlen(usr->pw_name));
	ft_putstr("  ");
	grp = getgrgid(filestat->st_gid);
	ft_putstr(grp->gr_name);
	ft_print_space(tab.c3 - ft_strlen(grp->gr_name));
	ft_putstr("  ");
	ft_print_space(tab.c4 - ft_cnt(filestat->st_size));
	ft_putnbr(filestat->st_size);
	ft_putstr(" ");
	mtime = ft_strncpy(mtime, ctime(&(filestat->st_mtime)) + 4, 12);
	ft_putstr(mtime);
	ft_putstr(" ");
}

size_t	ft_cnt(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

void	ft_print_total(int n)
{
	ft_putstr("total ");
	ft_putnbr(n);
	ft_putchar('\n');
}

void	ft_ls_max_length(t_list *list, t_ls_max_len *tab, char *file)
{
	t_list			*temp;
	struct stat		fstat;
	struct passwd	*usr;
	struct group	*grp;
	int				total;

	total = 0;
	temp = list;
	while (temp != NULL)
	{
		lstat(ft_strjoin(file, temp->content), &fstat);
		usr = getpwuid(fstat.st_uid);
		grp = getgrgid(fstat.st_gid);
		tab->c1 = (tab->c1 < ft_cnt(fstat.st_nlink) ?
				ft_cnt(fstat.st_nlink) : tab->c1);
		tab->c2 = (tab->c2 < ft_strlen(usr->pw_name) ?
				ft_strlen(usr->pw_name) : tab->c2);
		tab->c3 = (tab->c3 < ft_strlen(grp->gr_name) ?
				ft_strlen(grp->gr_name) : tab->c3);
		tab->c4 = (tab->c4 < ft_cnt(fstat.st_size) ?
				ft_cnt(fstat.st_size) : tab->c4);
		total += (fstat.st_blocks);
		temp = temp->next;
	}
	ft_print_total(total);
}
