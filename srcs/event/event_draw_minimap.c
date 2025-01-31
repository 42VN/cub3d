/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_draw_minimap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:33:19 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 15:12:20 by ktieu            ###   ########.fr       */
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
	ft_image_to_window(cub, cub->am.m_player, cub->player.cur_x, cub->player.cur_y);
}
