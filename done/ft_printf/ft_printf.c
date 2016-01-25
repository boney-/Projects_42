/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 12:22:12 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/03 19:34:57 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include <wctype.h>
#include <stdlib.h>
#include <libft.h>
#include "printf.h"

int		ft_printf(char *str, ...)
{
	t_env e;

	e.rvalue = 0;
	va_start(e.ap, str);
	ft_init(&e);
	ft_parse(str, &e);
	return (e.rvalue);
}
