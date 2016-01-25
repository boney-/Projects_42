/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:50:35 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/06 16:45:06 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		ft_init(t_env *e)
{
	e->args = NULL;
	if ((e->name_term = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("./ft_select error: No environement.\n", 2);
		return (-1);
	}
	if (tgetent(NULL, e->name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &e->term) == -1 || tcgetattr(0, &e->default_term) == -1)
		return (-1);
	e->term.c_lflag &= ~(ICANON | ECHO);
	e->term.c_lflag |= ISIG;
	e->term.c_cc[VMIN] = 1;
	e->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &e->term) == -1)
		return (-1);
	e->oldsize = get_winsize(1);
	return (0);
}
