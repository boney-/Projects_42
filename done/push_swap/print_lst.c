/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:42:39 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/27 20:18:11 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_lst(t_stack **list, char c)
{
	t_stack *temp;

	temp = *list;
	ft_putstr(c == '1' ? "Pile A: " : "Pile B: ");
	while (temp)
	{
		ft_putnbr(temp->nb);
		(temp->next ? ft_putstr(" ") : NULL);
		temp = temp->next;
	}
	ft_putchar('\n');
}

void	print_calls(t_list **list, t_env *e)
{
	int i;

	i = 0;
	while ((*list))
	{
		ft_putstr((*list)->content);
		ft_putchar((*list)->next ? ' ' : '\n');
		(*list) = (*list)->next;
		i++;
	}
	if (e->opt_w && i > 0)
	{
		ft_putstr("\nTotal: \033[1;31m");
		ft_putnbr(i);
		ft_putstr((i > 1 ? "\033[m operations.\n" : "\033[m operation.\n"));
	}
}
