/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:20:02 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/31 12:29:33 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *nstr;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) && (s2))
		return (ft_strdup(s2));
	else if ((s1) && !(s2))
		return (ft_strdup(s1));
	nstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!(nstr))
		return (NULL);
	nstr = ft_strcpy(nstr, s1);
	nstr = ft_strcat(nstr, s2);
	return (nstr);
}
