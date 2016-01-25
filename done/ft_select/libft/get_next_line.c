/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <jbonnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:52:59 by jbonnet           #+#    #+#             */
/*   Updated: 2014/12/19 17:29:32 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <libft.h>

int		ft_check_reste(char *reste)
{
	int	i;

	i = 0;
	if (reste == NULL)
		return (-1);
	while (reste[i] != '\n' && reste[i])
		i++;
	if (reste[i] == '\n')
		return (i);
	else
		return (-1);
}

char	*ft_join(char **dest, char *src)
{
	char *temp;

	temp = NULL;
	temp = ft_strjoin(*dest, src);
	if (!temp)
		return (NULL);
	ft_strdel(dest);
	return (temp);
}

char	*ft_cut(int n, char **reste, char **line)
{
	char	*str;

	str = NULL;
	*line = ft_strsub(*reste, 0, n);
	str = ft_strsub(*reste, n + 1, ft_strlen(*reste) - (n + 1));
	ft_strdel(reste);
	return (str);
}

int		get_next_line(int const fd, char **line)
{
	static char	*reste = NULL;
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	int			n;

	if (fd < 0 || !(line))
		return (-1);
	while ((n = ft_check_reste(reste)) < 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		else if (ret == 0)
		{
			*line = ft_join(&reste, buff);
			return (0);
		}
		buff[ret] = '\0';
		reste = ft_join(&reste, buff);
		if (!reste)
			return (-1);
		ft_strclr(buff);
	}
	reste = ft_cut(n, &reste, line);
	return (1);
}
