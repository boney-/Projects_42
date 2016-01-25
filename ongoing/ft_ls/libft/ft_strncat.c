/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:24:12 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/06 13:24:14 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char *ft_strncat(char *dest, const char *src, size_t n)
{
	int tdest;
	int i;

	i = 0;
	tdest = ft_strlen(dest);
	while (src[i] && i < (int)n)
	{
		dest[tdest + i] = src[i];
		i++;
	}
	dest[tdest + i] = '\0';
	return (dest);
}
