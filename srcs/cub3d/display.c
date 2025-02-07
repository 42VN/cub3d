/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:27:01 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/07 14:58:20 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Display the images using the IV plane (bottom right plane)
 */
void	cub3d_display(t_cub *c)
{
	t_asset_manager	*am;
	mlx_image_t		*player;

	am = &c->am;
	player = am->sprite_weapon->frames[am->sprite_weapon->idx];
	ft_image_to_window(c, am->ceiling, 0, 0);
	ft_image_to_window(c, am->floor, 0, HEIGHT / 2);
	ft_image_to_window(c, am->m_map_bg, 10, 10);
	ft_image_to_window(c, am->m_map, 10, 10);
	ft_image_to_window(c, player,
		WIDTH / 2 - (player->width / 2),
		HEIGHT - player->height + 10);
}