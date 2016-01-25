/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:51:16 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/26 14:19:45 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "select.h"

int		callc(int c)
{
	int		fd;

	if ((fd = open("/dev/tty", O_WRONLY)) == -1)
		return (-1);
	ft_putchar_fd(c, fd);
	close(fd);
	return (1);
}

int		puts_cmd(char *cmd)
{
	char	*res;

	if ((res = tgetstr(cmd, NULL)) == 0)
		return (-1);
	tputs(res, 0, callc);
	return (1);
}
