/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 13:32:09 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/27 20:18:10 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pushswap.h"

void	push(t_stack **src, t_stack **dest, char *str, t_env *e)
{
	t_stack	*temp;

	if (*src)
	{
		if (e->opt_c)
		{
			ft_putstr("\033[1;31m");
			ft_putstr(str);
			ft_putstr("\033[m\n");
		}
		add_to_lst(str, e);
		temp = *src;
		*src = ((*src)->next ? (*src)->next : NULL);
		temp->next = *dest;
		*dest = temp;
	}
}
