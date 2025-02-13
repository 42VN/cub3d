/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:39:26 by hitran            #+#    #+#             */
/*   Updated: 2025/02/13 10:25:58 by hitran           ###   ########.fr       */
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

static int	inside_check(t_map *map, char **temp, int32_t row, int32_t col)
{
	if (row < 0 || col < 0 || !temp[row]
		|| !temp[row][col] || temp[row][col] == ' ')
		return (1);		
	if (temp[row][col] == '1')
		return (0);
	temp[row][col] = '1';
	return (inside_check(map, temp, row + 1, col)
		|| inside_check(map, temp, row - 1, col)
		|| inside_check(map, temp, row, col + 1)
		|| inside_check(map, temp, row, col - 1));
}

static int	outside_check(t_map *map, char **temp, int32_t row, int32_t col)
{
	if (row < 0 || col < 0 || !temp[row]
		|| !temp[row][col] || temp[row][col] == '1')
		return (0);
	if (temp[row][col] == '0')
		return (1);		
	temp[row][col] = '1';
	return (outside_check(map, temp, row + 1, col)
		|| outside_check(map, temp, row - 1, col)
		|| outside_check(map, temp, row, col + 1)
		|| outside_check(map, temp, row, col - 1));
}

// int	grid2temp(char **temp, t_map *map)
// {
// 	int	row;
// 	int	col;

// 	row = -1;
// 	while (map && map->grid && map->grid[++row])
// 	{
// 		col = -1;
// 		while (map->grid[row][++col])
// 		{
// 			temp[row+1][col+1] = map->grid[row][col];
// 		}
// 	}
// 	return (EXIT_SUCCESS);
// }

char	**assign_newgrid(t_map *map, int offset)
{
	int		row;
	int		col;
	char	**res;

	res = ft_init_array(map->max_rows + offset + 1, map->max_cols + offset + 1);
	if (!res)
	{
		ft_error("ft_init_array");
		return (NULL);
	}
	row = -1;
	while (map && map->grid && map->grid[++row])
	{
		col = -1;
		while (map->grid[row][++col])
		{
			res[row + offset][col + offset] = map->grid[row][col];
		}
	}
	return (res);
}

static int	check_wall_surrounded(t_map *map, t_dpoint start)
{
	char	**temp;

	temp = assign_newgrid(map, 1); //->max_rows + 2, map->max_cols + 2);
	if (!temp)
		return (ft_error_ret("ft_calloc failed.", EXIT_FAILURE));
	if (inside_check(map, temp, start.y / CELL_PX + 1, start.x / CELL_PX + 1) 
		|| outside_check(map, temp, 0, 0))
	{
		ft_clean_array(&temp);
		return (ft_error_ret("Map is unclosed by walls.", EXIT_FAILURE));
	}
	ft_clean_array(&temp);
	temp = assign_newgrid(map, 0); //->max_rows + 2, map->max_cols + 2);
	if (!temp)
		return (ft_error_ret("ft_calloc failed.", EXIT_FAILURE));
	ft_clean_array(&map->grid);
	map->grid = temp;
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
