/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/01/30 15:43:20 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_line(t_map *map, char *line, int fd)
{
	if (!map->elem_done)
		return (read_element(map, line));
	else if (map->elem_done)
	{
		if (!line[0] && map->grid && !map->grid[0])
			return (EXIT_SUCCESS);
		else if (!line[0] && map->grid && map->grid[0])
			return (ft_error_ret("Map contains empty lines.", EXIT_FAILURE));
		return (read_map(map, line));
	}
	return (EXIT_SUCCESS);
}

int	read_map(t_map *map, int fd)
{
	char	*line;
	int		eof;

	eof = 0;
	map->grid = (char **)ft_calloc(BUFFER_SIZE, sizeof(char *));
	if (!map->grid)
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
		if (process_line(map, line, fd) == EXIT_FAILURE)
			return (map_error(map, line, fd));
		free(line);
	}
	return (validate_map(map, fd));
}
