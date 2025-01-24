/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/01/24 15:05:23 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	process_line(t_element *element, t_map *map, char *line, int fd)
{
	if (!element->done)
		return (read_element(element, line));
	else if (element->done)
	{
		if (!line[0] && map->arr && !map->arr[0])
			return (EXIT_SUCCESS);
		else if (!line[0] && map->arr && map->arr[0])
			return (ft_error_ret("Map contains empty lines.", EXIT_FAILURE));
		else if (read_map(map, line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
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
			if (!element->done || !map->arr[0])
			{
				ft_error("Invalid map.");
				return (map_error(element, map, line, fd));
			}
			break ;
		}
		printf("line = %s\n", line);
		if (process_line(element, map, line, fd) == EXIT_FAILURE)
			return (map_error(element, map, line, fd));
		free(line);
	}
	print_elements(element);
	print_map(map->arr);
	return (validate_map(element, map, fd));
}
