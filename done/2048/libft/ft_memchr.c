/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:20:48 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/19 12:21:06 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ps = s;

	while (n && s)
	{
		if (*ps == (unsigned char)c)
			return ((void*)ps);
		ps++;
		n--;
	}
	return (NULL);
}
