/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:25:01 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/06 16:39:25 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = ft_strlen(needle);
	if (k == 0)
		return ((char *)haystack);
	while (haystack[i] && i < (int)n)
	{
		while (haystack[i + j] == needle[j] && (int)n > j + i)
		{
			if (j == k - 1)
				return ((char*)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
