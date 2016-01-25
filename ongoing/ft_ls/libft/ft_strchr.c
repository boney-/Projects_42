/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:22:37 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/17 18:29:37 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strchr(const char *str, int c)
{
	while (*((char*)str) != c && *str)
		str++;
	if (*((char*)str) == c)
		return ((char*)str);
	else
		return (NULL);
}
