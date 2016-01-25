/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_element_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:43:29 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/26 14:19:42 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		get_max_element_size(t_env *e)
{
	int		max;
	int		temp;
	t_listd	*list;

	max = 0;
	list = e->start;
	while (list->next != e->start)
	{
		temp = ft_strlen(list->content);
		max = (max < temp ? temp : max);
		list = list->next;
	}
	temp = ft_strlen(list->content);
	max = (max < temp ? temp : max);
	return (max + 1);
}
