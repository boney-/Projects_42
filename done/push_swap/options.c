/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:43:46 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/27 20:18:12 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		check_options(char **tab, t_env *e)
{
	int	j;
	int	i;

	i = 1;
	while (tab[i] && tab[i][0] == '-')
	{
		j = 1;
		while (tab[i][j])
		{
			if (tab[i][j] == 'w')
				e->opt_w = 1;
			else if (tab[i][j] == 'v')
				e->opt_v = 1;
			else if (tab[i][j] == 'c')
				e->opt_c = 1;
			else if (ft_isdigit(tab[i][j]))
				return (i - 1);
			else
				quit_message("illegal option : use v,c and/or w.");
			j++;
		}
		i++;
	}
	return (i - 1);
}

void	print_opt_v(t_stack **stacka, t_stack **stackb)
{
	print_lst(stacka, '1');
	print_lst(stackb, '2');
	ft_putchar('\n');
}
