/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enclosed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:39:26 by hitran            #+#    #+#             */
/*   Updated: 2025/02/25 13:38:35 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static char	**init_array(int row, int col)
{
	char	**array;
	int		index;

	array = (char **)ft_calloc(row + 1, sizeof(char *));
	if (!array)
		return (NULL);
	index = -1;
	while (++index < row)
	{
		array[index] = (char *)ft_calloc(col + 1, sizeof(char));
		if (!array[index])
		{
			ft_clean_array(&array);
			return (NULL);
		}
		ft_memset(array[index], ' ', col);
	}
	return (array);
}

char	**assign_newgrid(t_map *map, int offset)
{
	int		row;
	int		col;
	char	**res;

	res = init_array(map->max_rows + 2 * offset, map->max_cols + 2 * offset);
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

bool	is_enclosed(t_map *map, t_dpoint start)
{
	char	**temp;

	temp = assign_newgrid(map, 1);
	if (!temp)
		return (ft_error_ret("ft_calloc failed.", false));
	if (inside_check(map, temp, start.y / CELL_PX + 1, start.x / CELL_PX + 1)
		|| outside_check(map, temp, 0, 0))
	{
		ft_clean_array(&temp);
		return (ft_error_ret("Map is unclosed by walls.", false));
	}
	ft_clean_array(&temp);
	temp = assign_newgrid(map, 0);
	if (!temp)
		return (ft_error_ret("ft_calloc failed.", false));
	ft_clean_array(&map->grid);
	map->grid = temp;
	return (true);
}
