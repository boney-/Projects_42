/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:32:36 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/17 18:50:34 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include "sh1.h"

int		main(int argc, char **argv, char **env)
{
	t_env e;

	e.env = env;
	e.list = NULL;
	ft_tab_to_lst(&e.list, env);
	(void)argc;
	(void)argv;
	signal(SIGINT, ft_handler);
	ft_putendl("\033[0;32m Hello ! You are now in sh1. \033[m");
	while (1)
		ft_get_stdin(&e);
	return (0);
}
