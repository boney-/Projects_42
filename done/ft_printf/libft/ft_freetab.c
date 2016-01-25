/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 14:35:06 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/16 14:23:16 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_freetab(void ***tab, unsigned int size)
{
	unsigned int	i;
	void			**temp;

	i = -1;
	temp = *tab;
	if (*tab)
	{
		while (++i < size)
		{
			free(temp[i]);
			temp[i] = NULL;
		}
		free(*tab);
		*tab = NULL;
	}
}
