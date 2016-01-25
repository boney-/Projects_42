/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:53:32 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 19:35:28 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_dec_to_bin(int nombre)
{
	char	*str;
	int		nb;
	int		i;
	int		end;
	int		temp;

	i = 0;
	temp = nombre;
	while (temp /= 2)
		i++;
	end = i;
	str = (char*)malloc(sizeof(char) * i + 1);
	if (nombre == 0)
		str[0] = '0';
	while (nombre && i >= 0)
	{
		nb = nombre % 2;
		str[i] = (char)nb + '0';
		nombre /= 2;
		i--;
	}
	str[end + 1] = '\0';
	return (str);
}
