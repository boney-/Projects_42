/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:47:19 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/27 20:18:12 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

void	quit_message(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

void	init_env(t_env *e)
{
	e->stacka = NULL;
	e->stackb = NULL;
	e->calls = NULL;
	e->opt_v = 0;
	e->opt_w = 0;
	e->opt_c = 0;
}

void	ft_lstpush_mod(t_list **alst, t_list *new)
{
	static t_list *last;

	if (*alst == NULL)
		*alst = new;
	else
		last->next = new;
	last = new;
}

void	add_to_lst(char *str, t_env *e)
{
	t_list	*new;

	new = ft_lstnew(str, ft_strlen(str) + 1);
	ft_lstpush_mod(&e->calls, new);
}

int		last_content(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	while (temp->next)
		temp = temp->next;
	return (temp->nb);
}
