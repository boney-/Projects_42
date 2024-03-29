/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:24:00 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/11 14:27:08 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}
