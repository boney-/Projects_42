/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:12:46 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/18 16:51:31 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_unsetenv(t_env *e)
{
	int		nb;

	nb = ft_chartab_len(e->args);
	if (nb == 2 && ft_check_var_env(e, e->args[1], NULL, 0))
		ft_lstdel_onelink(e);
	else
		ft_err("unsetenv : syntax error\nUsage : unsetenv [var].");
}

void	ft_setenv_value(t_env *e, char *arg1, char *arg2)
{
	t_list	*new;

	new = NULL;
	if (ft_strchar(arg1, '=') == 1)
		return (ft_err("setenv Syntax error."));
	if (ft_check_var_env(e, arg1, arg2, 3) == 0)
	{
		new = ft_lstnew(ft_strjoin(ft_strjoin(arg1, "="), arg2),
				ft_strlen(arg1) + 2);
		ft_lstpush(&e->list, new);
	}
}

void	ft_setenv(t_env *e)
{
	int		nb;
	t_list	*new;

	new = NULL;
	nb = ft_chartab_len(e->args);
	if (nb == 2)
	{
		if (ft_strchar(e->args[1], '=') == 1)
			return (ft_err("setenv Syntax error."));
		if (ft_check_var_env(e, e->args[1], NULL, nb))
			return ;
		new = ft_lstnew(ft_strjoin(e->args[1], "="), ft_strlen(e->args[1]) + 2);
		ft_lstpush(&e->list, new);
	}
	else if (nb == 3)
		ft_setenv_value(e, e->args[1], e->args[2]);
	else if (nb > 3)
		ft_err("Too many arguments.");
	else
		ft_err("Too few arguments.");
}

void	ft_env(t_env *e)
{
	t_list	*begin;

	if (!e->args[1] && e->list)
	{
		begin = e->list;
		while (e->list)
		{
			ft_putendl((char*)e->list->content);
			e->list = e->list->next;
		}
		e->list = begin;
	}
	else
		ft_err("env: too many arguments");
}
