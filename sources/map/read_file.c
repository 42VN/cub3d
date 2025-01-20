/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/01/20 13:04:51 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	process_line(t_element *element, t_map *map, char *line, int fd)
{
	if (!element->done)
	{
		if (read_element(element, line) == EXIT_FAILURE)
			return (read_elem_error(element, line, fd));
	}
	else if (element->done && line[0])
	{
		if (read_map(map, line) == EXIT_FAILURE)
			return (read_map_error(element, map, line, fd));
	}
	return (EXIT_SUCCESS);
}

int	read_file(t_element *element, t_map *map, int fd)
{
	char	*line;
	int		eof;

	eof = 0;
	while (1)
	{
		line = read_line(fd, &eof, BUFFER_SIZE);
		if (!line)
			return (EXIT_FAILURE);
		if (eof)
		{
			free(line);
			break ;
		}
		printf("line = %s\n", line); //test
		if (process_line(element, map, line, fd) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		free(line);
	}
	close(fd);
	print_elements(element);
	return (EXIT_SUCCESS);
}
