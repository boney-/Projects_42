/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 14:22:56 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/11 19:24:46 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pushswap.h"

void	rotate(t_stack **stack, t_env *e)
{
	t_stack *new;
	t_stack *temp;

	if (*stack)
	{
		(e->opt_c ? ft_putstr("\033[1;31mra\033[m\n") : NULL);
		add_to_lst("ra", e);
		new = *stack;
		*stack = (*stack)->next;
		new->next = NULL;
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	r_rotate(t_stack **stack, t_env *e)
{
	t_stack *new;
	t_stack *temp;

	temp = *stack;
	if (temp && temp->next)
	{
		(e->opt_c ? ft_putstr("\033[1;31mrra\033[m\n") : NULL);
		add_to_lst("rra", e);
		while (temp->next->next)
			temp = temp->next;
		new = temp->next;
		temp->next = NULL;
		new->next = *stack;
		*stack = new;
	}
}
