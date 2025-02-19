/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:25:55 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/19 13:34:34 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_map_player(t_cub *c, t_asset_manager *am)
{
    uint8_t	*player_px;
	uint8_t	*map_org = am->map->pixels;
	uint8_t	*m_player_org = am->m_player->pixels;

	player_px = ft_get_pixels(am->map, c->player.prev.x, c->player.prev.y);
	ft_del_pixels(player_px, am->map->width, M_PLAYER_SIZE, M_PLAYER_SIZE);

	am->map->pixels = ft_get_pixels(am->map, c->player.current.x, c->player.current.y);
	ft_copy_pixels(am->map, am->m_player, M_PLAYER_SIZE, M_PLAYER_SIZE);

	am->map->pixels = map_org;
	am->m_player->pixels = m_player_org;
}

void	draw_map(t_cub *c)
{
    draw_map_player(c, &c->am);
}