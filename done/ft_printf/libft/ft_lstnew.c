/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:59:13 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/12 14:47:49 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*element;

	element = (t_list*)malloc(sizeof(t_list));
	if (element)
	{
		if (!content)
		{
			element->content = NULL;
			element->content_size = 0;
		}
		else
		{
			element->content = (void *)content;
			element->content_size = content_size;
		}
		element->next = NULL;
	}
	return (element);
}
