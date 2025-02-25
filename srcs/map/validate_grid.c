/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:51:53 by hitran            #+#    #+#             */
/*   Updated: 2025/02/25 09:58:55 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_direction(char c)
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

static int	validate_characters(t_cub *cub, int row)
{
	int	col;

	col = 0;
	while (cub->map.grid[row][col])
	{
		if (!ft_strchr(" 01DNSEW", cub->map.grid[row][col]))
			return (ft_error_ret("Map contains invalid characters",
					EXIT_FAILURE));
		else if (ft_strchr("NSEW", cub->map.grid[row][col]))
		{
			if (cub->player.angle > 0)
				return (ft_error_ret("More than 1 player.", EXIT_FAILURE));
            cub->player.prev = (t_dpoint){col * CELL_PX, row * CELL_PX};
			cub->player.current = (t_dpoint){col * CELL_PX, row * CELL_PX};
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
	if (!is_enclosed(&cub->map, cub->player.current))
		return (map_error(&cub->map, NULL, fd));
	print_map(&cub->map);
	return (EXIT_SUCCESS);
}
