/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/01/24 13:48:04 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	process_line(t_element *element, t_map *map, char *line, int fd)
{
	if (!element->done)
	{
		if (read_element(element, line) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
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
	printf("Start: Player: [%d, %d] %d\n", map->start.row, map->start.col, map->start.direction);
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
			return (read_map_error(element, map, line, fd));
		free(line);
	}
	print_elements(element);
	print_map(map->arr);
	printf("Player: [%d, %d] %d\n", map->start.row, map->start.col, map->start.direction);
	// return (EXIT_SUCCESS);
	return (validate_map(element, map, fd));
}
