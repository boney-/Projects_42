/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:35:08 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/06 18:23:42 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;

	if (s)
	{
		i = ft_strlen(s);
		while (i >= 0)
		{
			s[i] = '\0';
			i--;
		}
	}
}
