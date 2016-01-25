/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 15:49:02 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/19 13:36:11 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh1.h"

int		ft_exec_cmd(char *cmd, t_env *e)
{
	pid_t	pid;
	char	*path;

	(void)pid;
	if ((path = ft_check_path(cmd, e)))
	{
		pid = fork();
		waitpid(-1, NULL, 0);
		if (e->args[1] && e->args[1][0] == '~')
		{
			e->args[1]++;
			e->args[1] = ft_strjoin(ft_get_var_env(&e->list, "HOME"),
					e->args[1]);
		}
		if (pid == 0)
			execve(path, e->args, e->env);
		return (1);
	}
	return (0);
}

int		ft_exec_builtins(char *cmd, t_env *e)
{
	char	**builtins;
	int		i;
	void	(*f[5])(t_env *);

	i = 0;
	ft_init(&builtins);
	f[0] = ft_exit;
	f[1] = ft_cd;
	f[2] = ft_env;
	f[3] = ft_setenv;
	f[4] = ft_unsetenv;
	while (i < 5)
	{
		if (ft_strcmp(cmd, builtins[i]) == 0)
		{
			f[i](e);
			return (1);
		}
		i++;
	}
	return (0);
}
