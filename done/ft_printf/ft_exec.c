/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:45:27 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/04 20:05:08 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_replace_wildcard(char *flags, int i, char *temp)
{
	char	*str;
	int		j;
	int		k;

	j = 0;
	if (temp[0] == '-' && flags[i - 1] == '.')
	{
		flags[i - 1] = '|';
		return (flags);
	}
	str = ft_strnew(ft_strlen(flags) + ft_strlen(temp));
	while (j < i)
	{
		str[j] = flags[j];
		j++;
	}
	k = 0;
	while (temp[k])
		str[j++] = temp[k++];
	while (flags[i + 1])
		str[j++] = flags[i++ + 1];
	str[j + 1] = '\0';
	return (str);
}

char	*ft_epur_digit(char *flags)
{
	int	j;

	j = 0;
	while (flags[j] && flags[j] != '.')
	{
		if (flags[j] >= '1' && flags[j] <= '9')
			flags[j] = '|';
		j++;
	}
	return (flags);
}

char	*ft_wildcards(char *flags, t_env *e)
{
	int		i;
	int		temp;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '*')
		{
			temp = va_arg(e->ap, int);
			if (flags[i - 1] != '.' && temp >= 0)
				flags = ft_epur_digit(flags);
			flags = ft_replace_wildcard(flags, i, ft_itoa(temp));
		}
		i++;
	}
	return (flags);
}

void	ft_exec_arg(char *str, int i, t_env *e)
{
	char	*flags;
	int		ret;

	flags = ft_wildcards(ft_strsub(str, 1, i), e);
	ft_up_flags(flags, 0, e);
	ret = ft_strlen(flags) - 1;
	if (flags[ret] == 's' && e->l == 0)
		ft_treat_string(flags, va_arg(e->ap, char*), e);
	else if (flags[ret] == '%')
		ft_treat_char(flags, '%', e);
	else if (flags[ret] == 'd' || flags[ret] == 'i' || flags[ret] == 'D')
		ft_treat_int(flags, e);
	else if (flags[ret] == 'p')
		ft_treat_address(flags, va_arg(e->ap, unsigned long), e);
	else if (flags[ret] == 'c' && e->l == 0)
		ft_treat_char(flags, va_arg(e->ap, int), e);
	else if (flags[ret] == 'o' || flags[ret] == 'u' || flags[ret] == 'x' ||
			flags[ret] == 'X' || flags[ret] == 'U' || flags[ret] == 'O')
		ft_treat_oux(flags, va_arg(e->ap, unsigned long), e);
	else if (flags[ret] == 'S' || (flags[ret] == 's' && e->l <= 1))
		ft_treat_gs(flags, va_arg(e->ap, wchar_t *), e);
	else if ((flags[ret] == 'C') || (flags[ret] == 'c' && e->l <= 1))
		ft_treat_gc(flags, va_arg(e->ap, wint_t), e);
	else if (ft_isprint(flags[ret]))
		ft_treat_char(flags, flags[ret], e);
}
