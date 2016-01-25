/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:18:27 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/25 17:58:01 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_atoi(char *str)
{
	int result;
	int fixe;

	result = 0;
	fixe = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		fixe = fixe * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = ((result * 10) + (*str - '0'));
		str++;
	}
	return (result * fixe);
}
