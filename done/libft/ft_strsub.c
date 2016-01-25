/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:52:15 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/07 13:16:35 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	int		i;

	nstr = ft_strnew(len);
	i = 0;
	if (!(nstr) || s == NULL)
		return (NULL);
	while (i < (int)len)
	{
		nstr[i] = s[i + start];
		i++;
	}
	return (nstr);
}
