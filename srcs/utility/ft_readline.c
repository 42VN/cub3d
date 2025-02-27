/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:39:40 by hitran            #+#    #+#             */
/*   Updated: 2025/02/27 14:29:47 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*realloc_buffer(char *buffer, int size)
{
	char	*new_buffer;

	new_buffer = (char *)ft_calloc(size, sizeof(char));
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	ft_memcpy(new_buffer, buffer, ft_strlen(buffer));
	free(buffer);
	return (new_buffer);
}

int	process_read(char *line, int fd, int *eof, int size)
{
	int		byte;
	char	c;
	int		index;

	index = 0;
	while (1)
	{
		byte = read(fd, &c, 1);
		if (byte == -1)
			return (ft_error_ret("Read", EXIT_FAILURE));
		if (byte == 0)
			*eof = 1;
		if (byte == 0 || c == '\n')
			break ;
		line[index++] = c;
		if (index >= size)
		{
			size += GRID_BUFFER;
			line = realloc_buffer(line, size);
			if (!line)
				return (ft_error_ret("realloc_buffer", EXIT_FAILURE));
		}
	}
	return (EXIT_SUCCESS);
}

char	*ft_readline(int fd, int *eof, int size)
{
	char	*line;

	line = (char *)ft_calloc(size, sizeof(char));
	if (!line || process_read(line, fd, eof, size) == EXIT_FAILURE)
		return (ft_error_ret_null("ft_calloc"));
	return (line);
}
