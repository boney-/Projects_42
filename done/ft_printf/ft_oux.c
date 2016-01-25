/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:51:32 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/04 13:13:59 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_treat_ogo(char *flags, unsigned long nombre, t_env *e)
{
	char	*str;

	(void)flags;
	if (e->l == 0 && !e->go)
		nombre = (unsigned)nombre;
	str = ft_dec_to_oct(nombre);
	if (e->diez && nombre != 0)
		str = ft_strjoin("0", str);
	ft_treat_int_str(str, e);
}

void	ft_treat_xgx(char *flags, unsigned long nombre, t_env *e)
{
	char	*str;

	(void)flags;
	nombre = (e->l > 0 ? nombre : (unsigned int)nombre);
	str = ft_dec_to_hex_ul(nombre, e);
	ft_treat_int_str(str, e);
}

void	ft_treat_oux(char *flags, unsigned long nombre, t_env *e)
{
	e->oct = 1;
	ft_treat_options(flags, e);
	if ((e->point && ft_atoi(e->precision[1]) == 0 && nombre == 0) &&
			((!e->diez && (e->o || e->go)) || (e->x || e->gx || e->u || e->gu)))
		return ;
	if (e->h > 0 && !e->go && !e->gu)
		nombre = (e->h % 2 ? (unsigned short)nombre : (unsigned char)nombre);
	else if (e->h > 0 && (e->go || e->gu))
		nombre = (e->go ? (unsigned short)nombre : nombre);
	if (e->o || e->go)
		ft_treat_ogo(flags, nombre, e);
	else if (e->x || e->gx)
		ft_treat_xgx(flags, nombre, e);
	else if (e->u || e->gu)
	{
		if (e->u && e->l == 0)
			nombre = (unsigned int)nombre;
		ft_treat_int_str(ft_itoa_ulong(nombre), e);
	}
}
