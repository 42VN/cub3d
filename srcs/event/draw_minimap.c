/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:13:08 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/05 15:13:09 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	event_draw_minimap(t_cub *cub, int32_t y, int32_t x)
{
	int	len;

	while (++y < cub->map.max_rows)
	{
		x = -1;
		len = ft_strlen(cub->map.grid[y]);
		while (++x < len)
		{
			if (cub->map.grid[y][x] == '1')
				ft_image_to_window(cub, cub->am.m_wall, x, y);
			else if (cub->map.grid[y][x] != ' ')
				ft_image_to_window(cub, cub->am.m_space, x, y);
		}
	}
	ft_image_to_window(cub, cub->am.m_player, cub->player.current.x / CELL_PX,
						cub->player.current.y / CELL_PX);
}
