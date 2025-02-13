/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:39:26 by hitran            #+#    #+#             */
/*   Updated: 2025/02/12 21:55:45 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_direction(char c)
{
	if (c == 'N')
		return (PI / 2);
	else if (c == 'S')
		return (3 * PI / 2);
	else if (c == 'W')
		return (PI);
	else if (c == 'E')
		return (2 * PI);
	return (0);
}

static int	inside_check(t_map *map, char **visited, int32_t row, int32_t col)
{
	if (row < 0 || col < 0 || !visited[row]
		|| !visited[row][col] || visited[row][col] == ' ')
		return (1);		
	if (visited[row][col] == '1')
		return (0);
	visited[row][col] = '1';
	return (inside_check(map, visited, row + 1, col)
		|| inside_check(map, visited, row - 1, col)
		|| inside_check(map, visited, row, col + 1)
		|| inside_check(map, visited, row, col - 1));
}

static int	outside_check(t_map *map, char **visited, int32_t row, int32_t col)
{
	if (row < 0 || col < 0 || !visited[row]
		|| !visited[row][col] || visited[row][col] == '1')
		return (0);
	if (visited[row][col] == '0')
		return (1);		
	visited[row][col] = '1';
	return (outside_check(map, visited, row + 1, col)
		|| outside_check(map, visited, row - 1, col)
		|| outside_check(map, visited, row, col + 1)
		|| outside_check(map, visited, row, col - 1));
}

static int	is_unclosed(t_map *map, char **visited, int32_t row, int32_t col)
{
	return (inside_check(map, visited, row + 1, col + 1) 
			|| outside_check(map, visited, 0, 0));
}

int	grid2visited(char **visited, t_map *map)
{
	int	row;
	int	col;

	row = -1;
	while (map && map->grid && map->grid[++row])
	{
		col = -1;
		while (map->grid[row][++col])
		{
			visited[row+1][col+1] = map->grid[row][col];
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_wall_surrounded(t_map *map, t_dpoint start)
{
	char	**visited;

	visited = ft_init_array(map->max_rows + 2, map->max_cols + 2);
	if (!visited)
		return (ft_error_ret("ft_calloc failed.", EXIT_FAILURE));
	if (grid2visited(visited, map) == EXIT_FAILURE)
	{
		ft_clean_array(&visited);
		return (EXIT_FAILURE);
	}
	if (is_unclosed(map, visited, start.y / CELL_PX, start.x / CELL_PX))
	{
		ft_clean_array(&visited);
		return (ft_error_ret("Map is unclosed by walls.", EXIT_FAILURE));
	}
	ft_clean_array(&visited);
	return (EXIT_SUCCESS);
}

static int	validate_characters(t_cub *cub, int row)
{
	int	col;

	col = 0;
	while (cub->map.grid[row][col])
	{
		if (!ft_strchr(" 01NSEW", cub->map.grid[row][col]))
			return (ft_error_ret("Map contains invalid characters",
					EXIT_FAILURE));
		else if (ft_strchr("NSEW", cub->map.grid[row][col]))
		{
			if (cub->player.angle > 0)
				return (ft_error_ret("More than 1 player.", EXIT_FAILURE));
			cub->player.current = (t_dpoint){col * CELL_PX, row * CELL_PX};
			cub->player.next = (t_dpoint){col * CELL_PX, row * CELL_PX};
			cub->player.angle =	get_direction(cub->map.grid[row][col]);
			cub->map.grid[row][col] = '0';
		}
		col++;
	}
	return (EXIT_SUCCESS);
}

int	validate_grid(t_cub *cub, int fd)
{
	int	row;

	row = 0;
	if (!is_done(&cub->map) || !cub->map.grid[0])
	{
		ft_error("Invalid map.");
		return (map_error(&cub->map, NULL, fd));
	}
	while (cub->map.grid && cub->map.grid[row])
	{
		if (validate_characters(cub, row) == EXIT_FAILURE)
			return (map_error(&cub->map, NULL, fd));
		row++;
	}
	if (!cub->player.angle)
	{
		ft_error("Player not found.");
		return (map_error(&cub->map, NULL, fd));
	}
	if (check_wall_surrounded(&cub->map, cub->player.current) == EXIT_FAILURE)
		return (map_error(&cub->map, NULL, fd));
	print_map(&cub->map);
	return (EXIT_SUCCESS);
}
