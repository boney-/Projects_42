/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:43:30 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/17 16:12:38 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*new_str;

	if (s && f)
	{
		i = 0;
		len = ft_strlen(s);
		new_str = (char *)malloc(len * sizeof(new_str));
		while (s[i] != '\0')
		{
			new_str[i] = f(i, s[i]);
			i++;
		}
		return (new_str);
	}
	return (NULL);
}
