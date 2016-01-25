/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:52:24 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/26 14:19:45 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		count_param(t_env *e)
{
	int	i;

	i = 0;
	while (e->args->next != e->start)
	{
		if (e->args->select == 1)
			i++;
		e->args = e->args->next;
	}
	if (e->args->select == 1)
		i++;
	e->args = e->start;
	return (i);
}

int		size_lst(t_env *e)
{
	int	i;

	i = 0;
	while (e->args->next != e->start)
	{
		e->args = e->args->next;
		i++;
	}
	i++;
	e->args = e->start;
	return (i);
}
