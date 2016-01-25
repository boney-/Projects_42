/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 13:21:36 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/13 16:30:12 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pushswap.h"

void	swap(t_stack **list, char *str, t_env *e)
{
	int temp;

	if ((*list)->next != NULL)
	{
		if (e->opt_c)
		{
			ft_putstr("\033[1;31m");
			ft_putstr(str);
			ft_putstr("\033[m\n");
		}
		add_to_lst(str, e);
		temp = (*list)->next->nb;
		(*list)->next->nb = (*list)->nb;
		(*list)->nb = temp;
	}
}
