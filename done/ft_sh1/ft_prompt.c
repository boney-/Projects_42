/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:28:43 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/18 13:06:42 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh1.h"

void	ft_prompt(void)
{
	char	*buf;

	buf = NULL;
	buf = ft_currentdir(ft_strsplit(getcwd(buf, 0), '/'));
	ft_putstr("\033[1;31m sh1 \033[m: \033[0;32m");
	ft_putstr(buf);
	ft_putstr("\033[m : \033[1;31m% \033[m>");
}

char	*ft_currentdir(char **dir)
{
	int		i;
	char	*path;

	path = NULL;
	i = ft_chartab_len(dir) - 1;
	while (dir[i] && i > (int)(ft_chartab_len(dir) - 4) && i >= 0)
	{
		dir[i] = ft_strjoin(dir[i], "/");
		path = ft_strjoin(dir[i--], path);
	}
	return ((path == NULL ? "/" : path));
}
