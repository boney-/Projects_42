/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:52:21 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/04 12:43:57 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_treat_address(char *flags, unsigned long adr, t_env *e)
{
	char	*nombre;

	ft_treat_options(flags, e);
	if (adr == 0 && e->point && ft_atoi(e->precision[1]) == 0)
		return (ft_putstr_mod("0x", e));
	nombre = ft_dec_to_hex_ul(adr, e);
	while (e->point && ft_atoi(e->precision[1]) > (int)ft_strlen(nombre))
		nombre = ft_strjoin("0", nombre);
	while (e->prespace && !e->moins && !e->point && e->zero &&
			ft_atoi(e->precision[0]) > (int)ft_strlen(nombre) + 2)
		nombre = ft_strjoin("0", nombre);
	while (e->prespace && e->moins && ft_atoi(e->precision[0]) >
			(int)ft_strlen(nombre) + 2)
		nombre = ft_strjoin(nombre, " ");
	nombre = ft_strjoin("0x", nombre);
	while (e->prespace && !e->moins && ft_atoi(e->precision[0]) >
			(int)ft_strlen(nombre))
		nombre = ft_strjoin(" ", nombre);
	ft_putstr_mod(nombre, e);
}
