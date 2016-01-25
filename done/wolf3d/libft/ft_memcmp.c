/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:20:58 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/25 14:02:32 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*ps1 = s1;
	const unsigned char		*ps2 = s2;

	while (n && s1 && s2)
	{
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		else
		{
			ps1++;
			ps2++;
		}
		n--;
	}
	return (0);
}
