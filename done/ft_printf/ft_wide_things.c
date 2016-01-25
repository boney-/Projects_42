/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wide_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:46:23 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 20:53:26 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_check_char(int i, t_env *e)
{
	char	*str;

	str = ft_dec_to_bin(i);
	i = ft_strlen(str);
	if (i <= 7)
		ft_fill_mask(e->tab[0], str, i - 1, e);
	else if (i <= 11)
		ft_fill_mask(e->tab[1], str, i - 1, e);
	else if (i <= 16)
		ft_fill_mask(e->tab[2], str, i - 1, e);
	else if (i <= 21)
		ft_fill_mask(e->tab[3], str, i - 1, e);
	else
		return ;
}

int		ft_precision_gs(wchar_t *str, t_env *e)
{
	int		i;
	int		len;

	i = 0;
	len = ft_wchar_len(str[i]);
	while (str[i] && len <= ft_atoi(e->precision[1]))
	{
		i++;
		len += ft_wchar_len(str[i]);
	}
	return (i);
}

void	ft_treat_gs(char *flags, wchar_t *str, t_env *e)
{
	int		i;
	int		nb;
	int		len;

	i = 0;
	nb = 20000;
	(void)flags;
	ft_treat_options(flags, e);
	if (str == 0)
		return (ft_putstr_mod("(null)", e));
	if (e->point)
		nb = ft_precision_gs(str, e);
	len = ft_wstrlen(str, nb);
	if (e->prespace && !e->moins && ft_atoi(e->precision[0]) > len)
		ft_print_char(ft_atoi(e->precision[0]) - len, (e->zero ? '0' : ' '), e);
	while (str[i] && i < nb)
		ft_check_char(str[i++], e);
	if (e->prespace && e->moins && ft_atoi(e->precision[0]) > len)
		ft_print_char(ft_atoi(e->precision[0]) - len, (e->zero ? '0' : ' '), e);
	return ;
}

void	ft_treat_gc(char *flags, wint_t c, t_env *e)
{
	ft_check_char(c, e);
	(void)flags;
	return ;
}
