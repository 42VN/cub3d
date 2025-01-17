/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:18:44 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/17 14:20:02 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

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

char	*ft_readline(int fd, int size)
{
	int		byte;
	char	c;
	char	*line;
	int		index;

	index = 0;
	line = (char *)ft_calloc(size, sizeof(char));
	if (!line)
		return (bad_alloc(NULL));
	while (1)
	{
		byte = read(fd, &c, 1);
		if (byte == -1)
			return (error_str(&line, "Reading failed."));
		if (byte == 0 || c == '\n')
			break ;
		line[index++] = c;
		if (index >= size)
		{
			size += BUFFER_SIZE;
			line = realloc_buffer(line, size);
			if (!line)
				return (bad_alloc(&line));
		}
	}
	line[index] = '\0';
	return (line);
}