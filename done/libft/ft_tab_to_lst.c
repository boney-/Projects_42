/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 13:11:40 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/15 13:13:42 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_tab_to_lst(t_list **list, char **tab)
{
	int		i;
	t_list	*new;

	i = 0;
	while (tab[i])
	{
		new = ft_lstnew(tab[i], ft_strlen(tab[i]) + 1);
		ft_lstpush(list, new);
		i++;
	}
}
