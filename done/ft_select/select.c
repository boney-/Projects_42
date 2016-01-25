/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 16:56:14 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/06 17:58:28 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <signal.h>
#include "select.h"

t_env	g_env;

void	quit_p(int a)
{
	if (a == SIGINT || a == SIGTERM)
		exit_prop(&g_env);
}

void	reprint(int a)
{
	(void)a;
	print_list(&g_env);
}

void	sig_cont(int a)
{
	(void)a;
	g_env.term.c_lflag &= ~(ICANON | ECHO);
	g_env.term.c_lflag |= ISIG;
	puts_cmd("vi");
	puts_cmd("ti");
	signal(SIGTSTP, &sig_stop);
	tcsetattr(0, TCSADRAIN, &g_env.term);
	print_list(&g_env);
}

void	sig_stop(int a)
{
	char	cp[2];

	cp[0] = g_env.term.c_cc[VSUSP];
	cp[1] = '\0';
	(void)a;
	puts_cmd("te");
	puts_cmd("ve");
	g_env.term.c_lflag |= ICANON;
	g_env.term.c_lflag |= ECHO;
	tcsetattr(0, TCSADRAIN, &g_env.term);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

int		main(int ac, char **av)
{
	if (ft_init(&g_env) == -1)
		return (0);
	if (ac > 1)
	{
		tab_to_lst(&g_env.args, av, &g_env);
		puts_cmd("cl");
		puts_cmd("vi");
		puts_cmd("ti");
		signal(SIGWINCH, &reprint);
		signal(SIGTSTP, &sig_stop);
		signal(SIGCONT, &sig_cont);
		signal(SIGINT, &quit_p);
		signal(SIGTERM, &quit_p);
		print_list(&g_env);
		buff_read(&g_env);
	}
	return (0);
}
