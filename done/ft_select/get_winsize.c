/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_winsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:54:55 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/26 14:19:47 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <fcntl.h>
#include "select.h"

int		get_winsize(int n)
{
	int				fd;
	struct winsize	ws;

	fd = open("/dev/tty", O_RDONLY);
	ioctl(fd, TIOCGWINSZ, &ws);
	close(fd);
	return (n == 1 ? ws.ws_row : ws.ws_col);
}
