/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:44:33 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/16 12:37:54 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pushswap.h"

int		lst_size(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int		fast_to_min(t_stack **stack, int min)
{
	int		mid;
	int		i;
	t_stack	*temp;

	temp = *stack;
	i = 0;
	mid = lst_size(stack) / 2;
	while (temp->nb != min)
	{
		i++;
		temp = temp->next;
	}
	return (i < mid ? 1 : 2);
}

void	handle_mins(t_stack **stacka, t_stack **stackb, int min, t_env *e)
{
	int min2;

	min2 = second_min(stacka, min);
	(fast_to_min(stacka, min) == 1 ? rotate(stacka, e) : r_rotate(stacka, e));
	if (e->opt_v)
		print_opt_v(stacka, stackb);
	if ((*stacka)->nb == min2)
	{
		push(stacka, stackb, "pb", e);
		if (e->opt_v)
			print_opt_v(stacka, stackb);
	}
}

void	sort_this_shit(t_stack **stacka, t_stack **stackb, t_env *e)
{
	int	ret;
	int min;

	if (e->opt_v && !is_list_sorted(stacka))
		print_opt_v(stacka, stackb);
	if ((*stacka)->nb > (*stacka)->next->nb)
		swap(stacka, "sa", e);
	while (!(ret = is_list_sorted(stacka)) || *stackb)
	{
		min = min_in_stack(stacka);
		while ((*stacka)->nb != min && !ret)
			handle_mins(stacka, stackb, min, e);
		if (!is_list_sorted(stacka))
			push(stacka, stackb, "pb", e);
		if (((*stackb) && (*stackb)->next) &&
				(*stackb)->nb < (*stackb)->next->nb)
		{
			(e->opt_v ? print_opt_v(stacka, stackb) : NULL);
			swap(stackb, "sb", e);
		}
		if (ret)
			push(stackb, stacka, "pa", e);
		if (e->opt_v)
			print_opt_v(stacka, stackb);
	}
}
