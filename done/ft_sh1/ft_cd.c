/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:15:39 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/19 12:48:06 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <unistd.h>
#include "sh1.h"

int		ft_cd_tilde(t_env *e)
{
	if (e->args[1][0] == '~')
	{
		e->args[1]++;
		e->args[1] = ft_strjoin(ft_get_var_env(&e->list, "HOME"), e->args[1]);
		if (ft_cd_error(e->args[1]))
			ft_update_pwd(e);
		return (0);
	}
	return (1);
}

int		ft_cd_exceptions(t_env *e)
{
	char	*buff;
	char	*args[2];

	buff = NULL;
	if (e->args[1][0] == '-' && ft_strlen(e->args[1]) == 1)
	{
		args[0] = ft_strdup("OLDPWD");
		args[1] = ft_strdup(getcwd(buff, 0));
		chdir(ft_get_var_env(&e->list, "OLDPWD"));
		ft_setenv_value(e, args[0], args[1]);
		buff = NULL;
		args[0] = ft_strdup("PWD");
		args[1] = ft_strdup(getcwd(buff, 0));
		ft_putendl(args[1]);
		ft_setenv_value(e, args[0], args[1]);
		return (0);
	}
	return ((ft_cd_tilde(e) ? 1 : 0));
}

int		ft_cd_error(char *args)
{
	if (access(args, F_OK) == -1)
	{
		ft_err(ft_strjoin("cd: no such file or directory : ", args));
		return (0);
	}
	if (access(args, R_OK) == -1)
	{
		ft_err(ft_strjoin("cd: permission denied: ", args));
		return (0);
	}
	if (opendir(args) == NULL)
	{
		ft_err(ft_strjoin("cd: not a directory: ", args));
		return (0);
	}
	return (1);
}

void	ft_cd(t_env *e)
{
	int		nb;

	nb = ft_chartab_len(e->args);
	if (nb == 2)
	{
		if ((ft_cd_exceptions(e) && ft_cd_error(e->args[1])))
			ft_update_pwd(e);
		return ;
	}
	else if (nb == 1)
	{
		chdir(ft_get_var_env(&e->list, "HOME"));
		return ;
	}
	ft_putstr_fd("cd: too many arguments\n", 2);
}
