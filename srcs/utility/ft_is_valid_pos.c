/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:59:32 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/19 13:45:25 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Function to check if a current poisition is valid
 * by getting (col, row) from (x, y) 
 */
int	ft_is_valid_pos(t_cub *c, int32_t x, int32_t y)
{
	int32_t	row;
	int32_t	col;

	if (x < 0 || (uint32_t)x >= c->map.width
		|| y < 0 || (uint32_t)y >= c->map.height
	)
		return (0);
	row = y / CELL_PX;
	col = x / CELL_PX;
	if (c->map.grid[row][col] == '1')
		return (0);
	return (1);
}
