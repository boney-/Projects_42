/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:58:23 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 19:48:58 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"

void	ft_init(t_env *e)
{
	e->zero = 0;
	e->space = 0;
	e->diez = 0;
	e->plus = 0;
	e->isint = 0;
	e->prespace = 0;
	e->nb = 0;
	e->precision = NULL;
	e->h = 0;
	e->l = 0;
	e->j = 0;
	e->o = 0;
	e->u = 0;
	e->x = 0;
	e->oct = 0;
	e->gx = 0;
	e->go = 0;
	e->gu = 0;
	e->point = 0;
	e->nargs = 0;
	e->list = NULL;
	e->moins = 0;
	ft_init_mask(e);
}
