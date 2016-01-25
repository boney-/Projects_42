/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:31:07 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/16 12:35:35 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

int		max_in_stack(t_stack **stack)
{
	int		max;
	t_stack	*temp;

	temp = *stack;
	max = temp->nb;
	while (temp)
	{
		if (temp->nb > max)
			max = temp->nb;
		temp = temp->next;
	}
	free(temp);
	return (max);
}

int		min_in_stack(t_stack **stack)
{
	int		min;
	t_stack	*temp;

	temp = *stack;
	min = temp->nb;
	while (temp)
	{
		if (temp->nb < min)
			min = temp->nb;
		temp = temp->next;
	}
	free(temp);
	return (min);
}

int		second_min(t_stack **stack, int nmin)
{
	int		min;
	t_stack	*temp;

	temp = *stack;
	min = (temp->nb == nmin && lst_size(stack) > 1 ? temp->next->nb : temp->nb);
	while (temp)
	{
		if (temp->nb < min && temp->nb != nmin)
			min = temp->nb;
		temp = temp->next;
	}
	free(temp);
	return (min);
}
