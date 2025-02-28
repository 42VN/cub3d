/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/02/28 15:18:00 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	copy_grid(char **new_grid, t_map *map)
{
	int	row;
	int	col;
	int	len;

	row = -1;
	while (++row < map->size - GRID_BUFFER)
	{
		new_grid[row] = (char *)ft_calloc(map->max_cols + 1, sizeof(char));
		if (!new_grid[row])
			return (ft_error_ret("copy_grid", EXIT_FAILURE));
		col = -1;
		len = ft_strlen(map->grid[row]);
		while (++col < len && map->grid[row][col])
			new_grid[row][col] = map->grid[row][col];
		while (col < map->max_cols)
			new_grid[row][col++] = ' ';
	}
	return (EXIT_SUCCESS);
}

static int	realloc_map(t_map *map)
{
	char	**new_grid;

	if (map->max_rows >= map->size)
	{
		map->size += GRID_BUFFER;
		new_grid = (char **)ft_calloc(map->size + 1, sizeof(char *));
		if (!new_grid)
			return (EXIT_FAILURE);
		if (copy_grid(new_grid, map) == EXIT_FAILURE)
		{
			ft_clean_array(&new_grid);
			return (EXIT_FAILURE);
		}
		ft_clean_array(&map->grid);
		map->grid = new_grid;
	}
	return (EXIT_SUCCESS);
}

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
