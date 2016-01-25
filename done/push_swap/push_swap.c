/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 12:53:07 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/16 12:44:42 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <libft.h>

void	check_dup(char **tab, int i)
{
	char	*temp;
	int		j;

	while (tab[i])
	{
		temp = tab[i];
		j = i + 1;
		while (tab[j])
		{
			if (ft_strequ(temp, tab[j]))
				quit_message("Error : No duplicates numbers allowed.");
			j++;
		}
		i++;
	}
}

void	error_handling(char **tab, int max)
{
	int		j;
	int		i;

	max++;
	i = max;
	while (tab[max])
	{
		j = 0;
		while (tab[max][j])
			(ft_isdigit(tab[max][j]) || (j == 0 && tab[max][j] == '-') ? j++ :
			quit_message("Error"));
		max++;
	}
	int_overflow(tab, i);
	check_dup(tab, i);
}

void	exception_case(t_stack **list, t_env *e)
{
	t_stack	*temp;

	if (lst_size(&e->stacka) > 2)
	{
		temp = *list;
		while ((*list)->next->next && (*list)->nb < (*list)->next->nb)
			(*list) = (*list)->next;
		if ((*list)->next->next == NULL && (*list)->nb > (*list)->next->nb)
		{
			r_rotate(list, e);
			r_rotate(list, e);
			swap(list, "sa", e);
			rotate(list, e);
			rotate(list, e);
		}
		*list = temp;
	}
}

int		main(int ac, char **av)
{
	t_env	e;
	int		err;

	if (ac < 2)
		quit_message("Push swap : too few arguments");
	init_env(&e);
	err = check_options(av, &e);
	error_handling(av, err);
	tab_to_lst(&e.stacka, av, err + 1);
	if (lst_size(&e.stacka) > 1)
	{
		exception_case(&e.stacka, &e);
		sort_this_shit(&e.stacka, &e.stackb, &e);
	}
	print_calls(&e.calls, &e);
	return (0);
}
