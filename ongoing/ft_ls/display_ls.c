/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 11:58:14 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/12 16:51:06 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "ls.h"

extern char		g_opt;
extern t_tab	g_tab_options[5];

int			ft_perror(int err, char **file)
{
	if (err == 2)
	{
		ft_putstr_fd("./ft_ls: ", 2);
		ft_putstr_fd(*file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (-1);
	}
	else if (err == 20)
	{
		ft_putstr(*file);
		ft_putstr("\n");
	}
	return (-1);
}

int			ft_fill_from_dir(char *file)
{
	struct dirent	*read;
	t_list			*list;
	DIR				*rep;
	void			*ptr;

	if ((rep = opendir(file)) == NULL)
		return (ft_perror(errno, &file));
	list = NULL;
	while ((read = readdir(rep)))
	{
		while (!(g_opt & OPT_A) && read->d_name[0] == '.' &&
				(read = readdir(rep)) != NULL)
			NULL;
		if (read == NULL)
			break ;
		ptr = ((g_opt & OPT_T) ? &ft_strtime_diff : &ft_strcmp_ls);
		ft_sort_lst(&list, read->d_name, ptr, file);
	}
	ft_display_list(list, file);
	return (1);
}

void		ft_display_link(char *link, char *file)
{
	char	buf[150];
	ssize_t	len;

	if ((len = readlink(ft_strjoin(file, link), buf, sizeof(buf) - 1)) != -1)
		buf[len] = '\0';
	ft_putstr(" -> ");
	ft_putstr(buf);
}

void		ft_display_list(t_list *list, char *file)
{
	t_ls_max_len	tab;
	struct stat		fstat;

	tab.c1 = 0;
	tab.c2 = 0;
	tab.c3 = 0;
	tab.c4 = 0;
	((g_tab_options[0].mask & g_opt) ? ft_ls_max_length(list, &tab, file) :
	NULL);
	while (list != NULL)
	{
		lstat(ft_strjoin(file, list->content), &fstat);
		if (g_tab_options[0].mask & g_opt)
			ft_show_perms(&(fstat), tab);
		ft_putstr(list->content);
		if (S_ISLNK(fstat.st_mode) && g_tab_options[0].mask & g_opt)
			ft_display_link(list->content, file);
		list = list->next;
		ft_putchar('\n');
	}
}

void		ft_print_space(int n)
{
	while (n > 0)
	{
		ft_putstr(" ");
		n--;
	}
}
