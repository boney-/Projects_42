/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:04:13 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/07 13:18:52 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*nstr;

	if (s && f)
	{
		size = ft_strlen(s);
		i = 0;
		nstr = ft_strnew(size);
		while (i < size)
		{
			nstr[i] = f(s[i]);
			i++;
		}
		return (nstr);
	}
	else
		return (NULL);
}
