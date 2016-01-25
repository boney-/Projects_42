/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:59:13 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/17 16:30:30 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nelement;

	nelement = (t_list*)malloc(sizeof(t_list));
	if (nelement == NULL)
		return (NULL);
	if (!(content))
	{
		nelement->content = NULL;
		nelement->content_size = 0;
	}
	else
	{
		nelement->content = malloc(sizeof(content));
		if (nelement->content == NULL)
			return (NULL);
		ft_memcpy((nelement->content), content, sizeof(content));
		nelement->content_size = content_size;
	}
	nelement->next = NULL;
	return (nelement);
}
