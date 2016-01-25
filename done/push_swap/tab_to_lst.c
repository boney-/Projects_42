/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 13:00:12 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/11 20:03:14 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	tab_to_lst(t_stack **list, char **tab, int i)
{
	t_stack	*new;

	while (tab[i])
	{
		new = lst_new(ft_atoi(tab[i]));
		stack_push(list, new);
		i++;
	}
}
