/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:45:58 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/06 17:46:12 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "select.h"

void	is_exist(char *path)
{
	struct stat stats;

	if (stat(path, &stats) == -1)
		return ;
	if (S_ISDIR(stats.st_mode))
		tputs("\033[1;35m", 0, callc);
	else if (S_ISREG(stats.st_mode))
	{
		tputs("\033[1;36m", 0, callc);
		if (access(path, X_OK) == 0)
			tputs("\033[1;31m", 0, callc);
	}
}

void	puts_str(t_listd *list, int i, t_env *e)
{
	int	li;
	int	max;

	li = get_winsize(1);
	i /= li - 1;
	if (i > e->sw)
	{
		e->sw = i;
		puts_cmd("ho");
	}
	max = i * get_max_element_size(e);
	is_exist(list->content);
	while (max--)
		puts_cmd("nd");
	if (list->select == 1)
		puts_cmd("mr");
	if (list->cursor == 1)
		puts_cmd("us");
	tputs(list->content, 0, callc);
	tputs("\n", 0, callc);
	tputs("\033[0m", 0, callc);
	puts_cmd("me");
}
