/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 14:55:10 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/26 15:02:11 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*brand_new_list;
	t_list		*the_beginning;
	t_list		*tempo;

	if (f == NULL && lst == NULL)
		return (NULL);
	tempo = f(lst);
	brand_new_list = ft_lstnew(tempo->content, tempo->content_size);
	if (brand_new_list == NULL)
		return (NULL);
	the_beginning = brand_new_list;
	while (lst->next != NULL)
	{
		tempo = f(lst->next);
		brand_new_list->next = ft_lstnew(tempo->content, tempo->content_size);
		if (brand_new_list->next == NULL)
		{
			ft_lstdel(&the_beginning, &ft_bzero);
			return (NULL);
		}
		lst = lst->next;
		brand_new_list = brand_new_list->next;
	}
	return (the_beginning);
}
