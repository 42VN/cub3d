/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:39:26 by hitran            #+#    #+#             */
/*   Updated: 2025/01/27 09:42:55 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	copy_map(char **visited, t_map *map, char rest)
{
	int	row;
	int	col;
	int	len;

	row = -1;
	while (map && map->arr && map->arr[++row])
	{
		visited[row] = (char *)ft_calloc(map->max_cols + 1, sizeof(char));
		if (!visited[row])
		{
			ft_clean_array(&visited);
			return (ft_error_ret("ft_calloc failed.", EXIT_FAILURE));
		}
		col = -1;
		len = ft_strlen(map->arr[row]);
		while (++col < len && map->arr[row][col])
			visited[row][col] = map->arr[row][col];
		while (rest && col < map->max_cols)
			visited[row][col++] = rest;
	}
	return (EXIT_SUCCESS);
}

static int	realloc_map(t_map *map)
{
	char	**new_array;

	if (map->max_rows >= map->size)
	{
		map->size += BUFFER_SIZE;
		new_array = (char **)ft_calloc(map->size, sizeof(char *));
		if (!new_array)
			return (EXIT_FAILURE);
		if (copy_map(new_array, map, 0) == EXIT_FAILURE)
		{
			ft_clean_array(&new_array);
			return (EXIT_FAILURE);
		}
		ft_clean_array(&map->arr);
		map->arr = new_array;
	}
	return (EXIT_SUCCESS);
}

int	read_map(t_map *map, char *line)
{
	int	len;

	if (!map || !line)
		return (EXIT_FAILURE);
	len = ft_strlen(line);
	if (len > map->max_cols)
		map->max_cols = len;
	if (realloc_map(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map->arr[map->max_rows] = ft_strdup(line);
	if (!map->arr[map->max_rows])
		return (ft_error_ret("Map reading: ft_strdup failed.", EXIT_FAILURE));
	map->max_rows++;
	return (EXIT_SUCCESS);
}
