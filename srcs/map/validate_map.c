/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:39:26 by hitran            #+#    #+#             */
/*   Updated: 2025/01/27 09:58:47 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_direction	get_direction(char c)
{
	if (c == 'N')
		return (N);
	else if (c == 'S')
		return (S);
	else if (c == 'W')
		return (W);
	else if (c == 'E')
		return (E);
	return (O);
}

static int	is_unclosed(t_map *map, char **visited, int32_t row, int32_t col)
{
	if (row < 0 || row >= map->max_rows || col < 0 || col >= map->max_cols)
		return (1);
	if (visited[row][col] == '1')
		return (0);
	visited[row][col] = '1';
	return (is_unclosed(map, visited, row + 1, col)
		|| is_unclosed(map, visited, row - 1, col)
		|| is_unclosed(map, visited, row, col + 1)
		|| is_unclosed(map, visited, row, col - 1));
}

static int	check_wall_surrounded(t_map *map)
{
	char	**visited;

	visited = (char **)ft_calloc(map->max_rows + 1, sizeof(char *));
	if (!visited)
		return (ft_error_ret("ft_calloc failed.", EXIT_FAILURE));
	if (copy_map(visited, map, ' ') == EXIT_FAILURE)
	{
		ft_clean_array(&visited);
		return (EXIT_FAILURE);
	}
	if (is_unclosed(map, visited, map->start.row, map->start.col))
	{
		ft_clean_array(&visited);
		return (ft_error_ret("Map is unclosed by walls.", EXIT_FAILURE));
	}
	ft_clean_array(&visited);
	return (EXIT_SUCCESS);
}

static int	validate_characters(t_map *map, int row)
{
	int	col;

	col = 0;
	while (map->arr[row][col])
	{
		if (!ft_strchr(" 01NSEW", map->arr[row][col]))
			return (ft_error_ret("Map contains invalid characters",
					EXIT_FAILURE));
		else if (ft_strchr("NSEW", map->arr[row][col]))
		{
			if (map->start.direction > 0)
				return (ft_error_ret("More than 1 player.", EXIT_FAILURE));
			map->start.col = col;
			map->start.row = row;
			map->start.direction = get_direction(map->arr[row][col]);
		}
		col++;
	}
	return (EXIT_SUCCESS);
}

int	validate_map(t_element *element, t_map *map, int fd)
{
	int	row;

	row = 0;
	if (!element->done || !map->arr[0])
	{
		ft_error("Invalid map.");
		return (map_error(element, map, NULL, fd));
	}
	while (map && map->arr && map->arr[row])
	{
		if (validate_characters(map, row) == EXIT_FAILURE)
			return (map_error(element, map, NULL, fd));
		row++;
	}
	if (!map->start.direction)
	{
		ft_error("Player not found.");
		return (map_error(element, map, NULL, fd));
	}
	if (check_wall_surrounded(map) == EXIT_FAILURE)
		return (map_error(element, map, NULL, fd));
	print_elements(element);
	print_map(map->arr);
	return (EXIT_SUCCESS);
}
