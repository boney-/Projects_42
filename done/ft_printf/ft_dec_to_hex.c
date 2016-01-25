/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:54:04 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/04 12:44:38 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_itohex(int nb, t_env *e)
{
	if (nb < 10)
		return ((char)nb + '0');
	return (e->gx == 0 ? (char)nb - 10 + 'a' : (char)nb - 10 + 'A');
}

char	*ft_dec_to_hex(long nombre, t_env *e)
{
	char	*str;
	int		nb;
	int		i;
	int		end;
	long	temp;

	i = 0;
	temp = nombre;
	while (temp /= 16)
		i++;
	end = i;
	str = (char*)malloc(sizeof(char) * i + 1);
	if (nombre == 0)
		str[0] = '0';
	while (nombre && i >= 0)
	{
		nb = nombre % 16;
		str[i] = ft_itohex(nb, e);
		nombre /= 16;
		i--;
	}
	str[end + 1] = '\0';
	return (str);
}

char	*ft_dec_to_hex_ul(unsigned long nombre, t_env *e)
{
	char			*str;
	int				nb;
	int				i;
	int				end;
	unsigned long	temp;

	i = 0;
	temp = nombre;
	while (temp /= 16)
		i++;
	end = i;
	str = (char*)malloc(sizeof(char) * i + 2);
	if (nombre == 0)
		str[0] = '0';
	while (nombre && i >= 0)
	{
		nb = nombre % 16;
		str[i] = ft_itohex(nb, e);
		nombre /= 16;
		i--;
	}
	str[end + 1] = '\0';
	return (str);
}
