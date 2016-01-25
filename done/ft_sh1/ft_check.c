/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:22:15 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/20 12:52:37 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "sh1.h"

int		ft_check_stdin(char *str, t_env *e)
{
	char	*cmd;

	str = ft_strtrim(str);
	cmd = ft_get_first_word(str, &e->args);
	if (ft_exec_builtins(cmd, e) == 0 && ft_exec_cmd(cmd, e) == 0)
	{
		ft_putstr_fd("sh1 : command not found : ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putchar_fd('\n', 2);
	}
	return (0);
}

char	*ft_check_path(char *cmd, t_env *e)
{
	char	**path;
	char	*var;
	int		i;

	i = 0;
	if ((var = ft_get_var_env(&e->list, "PATH")) == NULL)
		return (NULL);
	path = ft_strsplit(var, ':');
	if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0)
		return (cmd);
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd);
		if ((access(path[i], F_OK)) == 0 && access(path[i], X_OK) == 0)
			return (path[i]);
		i++;
	}
	ft_freetab((void ***)&path, i);
	return (NULL);
}

void	ft_init(char ***tab)
{
	char *str;

	str = ft_strdup("exit/cd/env/setenv/unsetenv");
	*tab = ft_strsplit(str, '/');
}

int		ft_check_var_env(t_env *e, char *args1, char *args2, int nb)
{
	t_list	*begin;

	begin = e->list;
	while (e->list)
	{
		if (ft_strequ((ft_strsplit(e->list->content, '='))[0], args1))
		{
			if (nb > 0)
			{
				e->list->content = (nb == 2 ? ft_strjoin((ft_strsplit(
				e->list->content, '='))[0], "=") : ft_strjoin(
				ft_strjoin(args1, "="), args2));
			}
			e->list = begin;
			return (1);
		}
		e->list = e->list->next;
	}
	e->list = begin;
	return (0);
}
