/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:27:58 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/17 18:50:25 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "sh1.h"

void	ft_update_pwd(t_env *e)
{
	char *buff;
	char *args[2];

	buff = NULL;
	args[0] = ft_strdup("OLDPWD");
	args[1] = ft_get_var_env(&e->list, "PWD");
	chdir(e->args[1]);
	ft_setenv_value(e, args[0], args[1]);
	args[0] = ft_strdup("PWD");
	args[1] = ft_strdup(getcwd(buff, 0));
	ft_setenv_value(e, args[0], args[1]);
}
