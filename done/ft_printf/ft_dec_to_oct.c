/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:53:10 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 19:35:52 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_dec_to_oct(unsigned long nombre)
{
	char			*str;
	int				nb;
	int				i;
	int				end;
	unsigned long	temp;

	i = 0;
	temp = nombre;
	while (temp /= 8)
		i++;
	end = i;
	str = (char*)malloc(sizeof(char) * i + 1);
	if (nombre == 0)
		str[0] = '0';
	while (nombre && i >= 0)
	{
		nb = nombre % 8;
		str[i] = (char)nb + '0';
		nombre /= 8;
		i--;
	}
	str[end + 1] = '\0';
	return (str);
}
