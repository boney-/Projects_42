/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:48:24 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 19:33:05 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_wstrlen(wchar_t *str, int max)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] && i < max)
		len += ft_wchar_len(str[i++]);
	return (len);
}

int		ft_wchar_len(int i)
{
	char	*str;

	str = ft_dec_to_bin(i);
	i = ft_strlen(str);
	if (i <= 7)
		return (1);
	else if (i <= 11)
		return (2);
	else if (i <= 16)
		return (3);
	else if (i <= 21)
		return (4);
	else
		return (0);
}
