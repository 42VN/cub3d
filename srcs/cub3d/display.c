/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:27:01 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 17:38:00 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Display the images using the IV plane (bottom right plane)
 */
void	cub3d_display(t_cub *c)
{
	t_asset_manager	*am;

	am = &c->am;
	ft_image_to_window(c, am->ceiling, 0, 0);
	ft_image_to_window(c, am->floor, 0, HEIGHT / 2);
	ft_image_to_window(c, am->m_map_bg, M_WIDTH, M_HEIGHT);
	ft_image_to_window(c, am->m_map, M_WIDTH, M_HEIGHT);

	// debugging
	ft_image_to_window(c, am->sprite_weapon->frames[am->sprite_weapon->idx], M_WIDTH, M_HEIGHT);
}