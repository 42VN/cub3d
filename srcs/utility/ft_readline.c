/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:17:24 by hitran            #+#    #+#             */
/*   Updated: 2025/02/28 15:23:33 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	realloc_buffer(char **buffer, int size)
{
	char	*new_buffer;
	int		index;

	new_buffer = (char *)ft_calloc(size + 1, sizeof(char));
	if (!new_buffer)
	{
		free(*buffer);
		return ;
	}
	index = -1;
	while ((*buffer)[++index])
		new_buffer[index] = (*buffer)[index];
	free(*buffer);
	*buffer = new_buffer;
}

static int	process_read(char **line, int fd, int *eof, int size)
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
		(*line)[index++] = c;
		if (index >= size)
		{
			size += GRID_BUFFER;
			realloc_buffer(line, size);
			if (!*line)
				return (ft_error_ret("realloc_buffer", EXIT_FAILURE));
		}
	}
	return (EXIT_SUCCESS);
}

char	*ft_readline(int fd, int *eof)
{
	char	*line;

	line = (char *)ft_calloc(GRID_BUFFER + 1, sizeof(char));
	if (!line || process_read(&line, fd, eof, GRID_BUFFER) == EXIT_FAILURE)
		return (ft_error_ret_null("ft_calloc"));
	return (line);
}
