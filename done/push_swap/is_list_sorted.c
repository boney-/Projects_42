/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_list_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:46:39 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/27 20:18:14 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		is_list_sorted(t_stack **stacka)
{
	t_stack *temp;

	temp = *stacka;
	while (temp && temp->next)
	{
		if (temp->nb > temp->next->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}
