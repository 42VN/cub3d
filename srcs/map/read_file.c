/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/01/27 09:16:33 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_line(t_element *element, t_map *map, char *line, int fd)
{
	if (!element->done)
		return (read_element(element, line));
	else if (element->done)
	{
		if (!line[0] && map->arr && !map->arr[0])
			return (EXIT_SUCCESS);
		else if (!line[0] && map->arr && map->arr[0])
			return (ft_error_ret("Map contains empty lines.", EXIT_FAILURE));
		return (read_map(map, line));
	}
	return (EXIT_SUCCESS);
}

int	read_file(t_element *element, t_map *map, int fd)
{
	char	*line;
	int		eof;

	eof = 0;
	map->arr = (char **)ft_calloc(BUFFER_SIZE, sizeof(char *));
	if (!map->arr)
		return (ft_error_ret("Map allocation failed.", 1));
	map->size = BUFFER_SIZE;
	while (1)
	{
		line = ft_readline(fd, &eof, BUFFER_SIZE);
		if (!line)
			return (EXIT_FAILURE);
		if (eof)
		{
			free(line);
			break ;
		}
		if (process_line(element, map, line, fd) == EXIT_FAILURE)
			return (map_error(element, map, line, fd));
		free(line);
	}
	return (validate_map(element, map, fd));
}
