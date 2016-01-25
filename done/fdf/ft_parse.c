/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 17:40:50 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/19 11:54:22 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "fdf.h"

int				*ft_parse(char *file, t_list **map)
{
	int		fd;
	int		y;
	char	*line;
	char	**values;

	y = 0;
	line = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error("Fichier introuvable.");
	while (get_next_line(fd, &line))
	{
		values = ft_strsplit(line, ' ');
		ft_lstpush(map, ft_linetostruct(values, y++));
		ft_freetab((void ***)(&values), ft_chartab_len(values));
		free(line);
	}
	return (0);
}
