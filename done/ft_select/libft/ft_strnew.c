/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:24:53 by jbonnet           #+#    #+#             */
/*   Updated: 2014/11/17 16:11:47 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *memory;

	memory = NULL;
	memory = (char *)malloc(sizeof(*memory) * (size + 1));
	if (!memory)
		return (NULL);
	else
		ft_bzero((void*)memory, size + 1);
	return (memory);
}
