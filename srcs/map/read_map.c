/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/02/03 10:31:16 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_grid(t_map *map, char *line)
{
	int	len;

	if (!map || !line)
		return (EXIT_FAILURE);
	len = ft_strlen(line);
	if (len > map->max_cols)
		map->max_cols = len;
	if (realloc_map(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map->grid[map->max_rows] = ft_strdup(line);
	if (!map->grid[map->max_rows])
		return (ft_error_ret("Map reading: ft_strdup failed.", EXIT_FAILURE));
	map->max_rows++;
	return (EXIT_SUCCESS);
}

static int	process_line(t_cub *cub, char *line, int fd)
{
	if (!is_done(&cub->map))
		return (read_element(&cub->map, line));
	else
	{
		if (!line[0] && cub->map.grid && !cub->map.grid[0])
			return (EXIT_SUCCESS);
		else if (!line[0] && cub->map.grid && cub->map.grid[0])
			return (ft_error_ret("Map contains empty lines.", EXIT_FAILURE));
		return (read_grid(&cub->map, line));
	}
	return (EXIT_SUCCESS);
}

int	read_map(t_cub *cub, int fd)
{
	char	*line;
	int		eof;

	eof = 0;
	cub->map.grid = (char **)ft_calloc(BUFFER_SIZE, sizeof(char *));
	if (!cub->map.grid)
		return (ft_error_ret("Map allocation failed.", 1));
	cub->map.size = BUFFER_SIZE;
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
		if (process_line(cub, line, fd) == EXIT_FAILURE)
			return (map_error(&cub->map, line, fd));
		free(line);
	}
	return (validate_grid(cub, fd));
}
