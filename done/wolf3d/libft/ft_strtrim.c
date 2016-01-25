/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:44:40 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/07 17:13:24 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const	*bgn;
	char const	*end;
	char		*new_str;

	bgn = NULL;
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (!(*s == ' ' || *s == '\n' || *s == '\t'))
		{
			if (bgn == NULL)
				bgn = s;
			end = s;
		}
		s++;
	}
	if (bgn == NULL)
		return (ft_strnew(0));
	new_str = ft_strnew(end - bgn + 2);
	s = bgn;
	while (s <= end)
		*new_str++ = *s++;
	*new_str = '\0';
	return (new_str - (end - bgn + 1));
}
