/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:22:26 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/31 12:29:11 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int tdest;
	int i;

	i = 0;
	tdest = ft_strlen(dest);
	while (src[i])
	{
		dest[tdest + i] = src[i];
		i++;
	}
	dest[tdest + i] = '\0';
	return (dest);
}
