/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:20:36 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/17 16:10:32 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void				*mema;
	unsigned int		counter;
	char				*buff;

	counter = 0;
	mema = (void *)malloc(size);
	buff = (char *)mema;
	if (mema != NULL)
	{
		while (counter++ < size)
			*buff++ = 0;
	}
	return (mema);
}
