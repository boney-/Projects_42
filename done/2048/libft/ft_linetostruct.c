/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linetostruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/04 17:42:25 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/18 17:43:57 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

t_list		*ft_linetostruct(char **values, int y)
{
	unsigned int	i;
	t_values		*val;

	i = 0;
	val = NULL;
	if (!values)
		return (NULL);
	if (!(val = (t_values *)malloc(sizeof(*val))))
		return (NULL);
	val->tab = NULL;
	val->size = ft_chartab_len(values);
	val->y = y;
	if (!(val->tab = (int *)malloc(sizeof(int) * (val->size))))
		return (NULL);
	while (values[i])
	{
		val->tab[i] = ft_atoi(values[i]);
		i++;
	}
	return (ft_lstnew((const void *)(val), sizeof(t_values *)));
}
