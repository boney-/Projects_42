/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 14:31:46 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/27 20:18:13 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

t_stack	*lst_new(int content)
{
	t_stack	*element;

	element = (t_stack*)malloc(sizeof(t_stack));
	if (element)
	{
		if (!content)
			element->nb = 0;
		else
			element->nb = content;
		element->next = NULL;
	}
	return (element);
}
