/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:21:58 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/25 17:56:54 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d <= s)
		return (ft_memcpy(d, s, n));
	else if (d > s)
	{
		s += n;
		d += n;
		while (n--)
			*--d = *--s;
	}
	return (d);
}
