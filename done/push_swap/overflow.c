/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 15:42:44 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/27 20:18:11 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	int_overflow(char **tab, int i)
{
	int		over;

	while (tab[i])
	{
		over = (tab[i][0] == '-' ? 11 : 10);
		if ((int)ft_strlen(tab[i]) > over)
			quit_message("Error (int overflow).");
		else if ((int)ft_strlen(tab[i]) == over)
		{
			if (tab[i][over - 10] > '2' || tab[i][over - 9] > '1' ||
tab[i][over - 8] > '4' || tab[i][over - 7] > '7' || tab[i][over - 6] > '4' ||
tab[i][over - 5] > '8' || tab[i][over - 4] > '3' || tab[i][over - 3] > '6' ||
tab[i][over - 2] > '4' || tab[i][over - 1] > (over == 11 ? '8' : '7'))
				quit_message("Error (int overflow).");
		}
		i++;
	}
}
