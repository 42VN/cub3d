/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:13:08 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/21 15:21:04 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_x(t_cub *c, int32_t *x, int32_t *offset_x)
{
	int32_t	start_x;

	*offset_x = M_WIDTH;
	start_x = c->player.current.x - (M_WIDTH / 2);
	*x = ft_max(start_x, 0);
	if (*x + M_WIDTH > c->map.width)
	{
		*x = ft_max(c->map.width - M_WIDTH, 0);
		if (*x == 0)
			*offset_x = c->map.width;
	}
}

static void	get_y(t_cub *c, int32_t *y, int32_t *offset_y)
{
	int32_t	start_y;

	*offset_y = M_HEIGHT;
	start_y = c->player.current.y - (M_HEIGHT / 2);
	*y = ft_max(start_y, 0);
	if (*y + M_HEIGHT > c->map.height)
	{
		*y = ft_max(c->map.height - M_HEIGHT, 0);
		if (*y == 0)
			*offset_y = c->map.height;
	}
}

void	draw_minimap(t_cub *c)
{
	uint8_t	*original;
	int32_t	x;
	int32_t	y;
	int32_t	offset_x;
	int32_t	offset_y;

	original = c->am.map->pixels;
	get_x(c, &x, &offset_x);
	get_y(c, &y, &offset_y);
	c->am.map->pixels = ft_get_pixels(c->am.map, x, y);
	ft_copy_pixels(c->am.m_map, c->am.map, offset_x, offset_y);
	c->am.map->pixels = original;
}
