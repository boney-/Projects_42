/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:25:10 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/06 13:25:12 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
	int tstr;
	int i;

	tstr = ft_strlen(str);
	i = 0;
	while (i++ < tstr)
		str++;
	i = 0;
	while (*((char*)str) != c && tstr > i++)
		str--;
	if (*((char*)str) == c)
		return ((char*)str);
	else
		return (NULL);
}
