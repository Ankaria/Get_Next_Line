/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:17:18 by elerika           #+#    #+#             */
/*   Updated: 2021/11/16 14:17:21 by elerika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	change_line(char	*buf, char	**line)
{
	char	*s;

	s = ft_strchr(buf, '\n');
	*s = '\0';
	*line = ft_strjoin(*line, buf);
	*line = ft_strjoin(*line, "\n");
	s++;
	ft_strncpy(buf, s, ft_strlen(s) + 1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	long		i;

	line = NULL;
	i = 1;
	if (read(fd, 0, 0) == -1)
		return (0);
	while ((ft_strchr(buf, '\n') == 0) && i > 0)
	{
		line = ft_strjoin(line, buf);
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
	}
	if (i < 0 || (i == 0 && line[0] == '\0'))
	{
		free (line);
		return (0);
	}
	if (ft_strchr(buf, '\n'))
		change_line(buf, &line);
	return (line);
}
