/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:54:47 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/04 20:04:27 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_treat_int_str(char *nombre, t_env *e)
{
	int	nb;

	nb = (nombre[0] == '-' ? 0 : 1);
	nombre = (!nb && (e->zero || e->point) ? nombre + 1 : nombre);
	while ((e->point && ft_atoi(e->precision[1]) > (int)ft_strlen(nombre))
	|| (e->zero && !e->point && ft_atoi(e->precision[0]) >
		(int)ft_strlen(nombre) + (nb ? 1 : 0) && !e->moins))
		nombre = ft_strjoin("0", nombre);
	if (e->plus && nb && !e->oct)
		nombre = ft_strjoin("+", nombre);
	else if (e->space && nb && !e->oct)
		nombre = ft_strjoin(" ", nombre);
	if (!nb && e->zero && !e->point)
	{
		if (nombre[0] == '0')
			nombre[0] = '-';
		else
			nombre = ft_strjoin("-", nombre);
	}
	else if (!nb && e->point)
		nombre = ft_strjoin("-", nombre);
	if ((e->x || e->gx) && (e->diez) && (nombre[0] != '0' ||
				ft_atoi(nombre) != 0))
		nombre = ft_strjoin((e->x ? "0x" : "0X"), nombre);
	ft_justification(nombre, e);
}

void	ft_treat_long_int(long nb, t_env *e)
{
	char	*nombre;

	e->isint = 1;
	nombre = ft_itoa_long(nb);
	ft_treat_int_str(nombre, e);
}

void	ft_treat_normal_int(int nb, t_env *e)
{
	char	*nombre;

	e->isint = 1;
	if (e->h > 0 && e->h % 2)
		nb = (short)nb;
	else if (e->h > 0 && !(e->h % 2))
		nb = (signed char)nb;
	if (e->point && ft_atoi(e->precision[1]) == 0 && nb == 0)
		return ;
	nombre = ft_itoa(nb);
	ft_treat_int_str(nombre, e);
}

void	ft_treat_int(char *flags, t_env *e)
{
	ft_treat_options(flags, e);
	if (e->l > 0 || e->j > 0)
		ft_treat_long_int(va_arg(e->ap, long), e);
	if (e->l == 0 && e->j == 0)
		ft_treat_normal_int(va_arg(e->ap, int), e);
}
