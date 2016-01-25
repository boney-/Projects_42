/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mask.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:59:00 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/04 15:34:26 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_init_mask(t_env *e)
{
	e->tab[0] = "0xxxxxxx";
	e->tab[1] = "110xxxxx 10xxxxxx";
	e->tab[2] = "1110xxxx 10xxxxxx 10xxxxxx";
	e->tab[3] = "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx";
}
