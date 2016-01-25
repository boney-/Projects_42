/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 17:55:47 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/12 16:51:03 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char		g_opt;

t_tab		g_tab_options[5] =
{
	{OPT_L, 'l'},
	{OPT_A, 'a'},
	{OPT_R, 'r'},
	{OPT_T, 't'},
	{OPT_1, '1'}
};

int		main(int argc, char **argv)
{
	int		i;
	int		inter;
	int		ret;

	g_opt = 0;
	i = ft_check_options(argc, argv);
	if (ft_check_illegal(argv, i) == 0)
		return (-1);
	if (argv[i] == NULL)
		ft_fill_from_dir("./");
	else
	{
		inter = ((argv[i + 1]) ? 1 : 0);
		while (argv[i])
		{
			((inter == 1) ? ft_prez(argv[i]) : NULL);
			argv[i] = ft_add_slash(argv[i]);
			ret = ft_fill_from_dir(argv[i]);
			((argv[i + 1] && ret != -1) ? ft_putstr("\n") : NULL);
			i++;
		}
	}
	return (0);
}

int		ft_check_options(int nb, char **args)
{
	int		count;
	int		temp;
	int		i;

	count = 1;
	while (args[count] && count < nb && args[count][0] == '-')
	{
		i = 0;
		while (args[count][i])
		{
			if (args[count][1] == '-')
				return (count + 1);
			temp = 0;
			while (temp < 5 && args[count][i] != g_tab_options[temp].option)
				temp++;
			g_opt = (temp < 4 ? g_opt | g_tab_options[temp].mask : g_opt);
			i++;
		}
		count++;
	}
	return (count);
}

int		ft_strcmp_ls(const char *s1, const char *s2, char *file)
{
	(void)file;
	if (ft_strcmp(s1, s2) > 0)
		return ((OPT_R & g_opt ? -1 : 1));
	else
		return ((OPT_R & g_opt ? 1 : -1));
}

void	ft_sort_lst(t_list **list, char *str, int (*f)(const char*,
			const char*, char *file), char *file)
{
	t_list			*temp;
	t_list			*new;

	new = malloc(sizeof(*new));
	new->content = str;
	new->next = NULL;
	temp = *list;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	if ((*f)(str, temp->content, file) < 0)
	{
		new->next = *list;
		*list = new;
		return ;
	}
	while (temp->next != NULL && (*f)(str, temp->next->content, file) > 0)
		temp = temp->next;
	new->next = temp->next;
	temp->next = new;
}

int		ft_strtime_diff(const char *s1, const char *s2, char *file)
{
	struct stat fstat1;
	struct stat fstat2;

	lstat(ft_strjoin(file, s1), &fstat1);
	lstat(ft_strjoin(file, s2), &fstat2);
	if (fstat1.st_mtime > fstat2.st_mtime)
		return ((g_opt & OPT_R ? 1 : -1));
	else if (fstat1.st_mtime < fstat2.st_mtime)
		return ((g_opt & OPT_R ? -1 : 1));
	else
		return (ft_strcmp_ls(s1, s2, file));
}
