/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:47:39 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/12 17:07:57 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

extern t_tab	g_tab_options[5];
extern char		g_opt;

char	*ft_add_slash(char *file)
{
	struct stat		fstat;
	t_ls_max_len	tab;

	stat(file, &fstat);
	if (S_ISDIR(fstat.st_mode))
	{
		if (file[ft_strlen(file)] == '/')
			return (file);
		file = ft_strjoin(file, "/");
		return (file);
	}
	tab.c1 = 0;
	tab.c2 = 0;
	tab.c3 = 0;
	tab.c4 = 0;
	if (S_ISREG(fstat.st_mode))
	{
		if (g_opt & OPT_L)
			ft_show_perms(&fstat, tab);
	}
	return (file);
}

int		ft_check_ill_options(char c)
{
	if (c == g_tab_options[0].option)
		return (1);
	if (c == g_tab_options[1].option)
		return (1);
	if (c == g_tab_options[2].option)
		return (1);
	if (c == g_tab_options[3].option)
		return (1);
	if (c == g_tab_options[4].option)
		return (1);
	if (c == '-')
		return (1);
	return (0);
}

int		ft_check_illegal(char **av, int max)
{
	int		i;
	int		j;
	int		ret;

	i = 1;
	j = 0;
	while (i < (max))
	{
		j = 0;
		while (av[i][j])
		{
			ret = ft_check_ill_options(av[i][j]);
			if (ret == 0)
			{
				ft_putstr_fd("./ft_ls: illegal option -- ", 2);
				ft_putchar_fd(av[i][j], 2);
				ft_putstr_fd("\nusage: ./ft_ls [-lart] [file ...]\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_prez(char *file)
{
	struct stat	fstat;

	stat(file, &fstat);
	if (S_ISDIR(fstat.st_mode))
	{
		ft_putstr(file);
		ft_putstr(":\n");
	}
}
