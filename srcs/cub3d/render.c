/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:06:00 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/23 17:07:52 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Render the images using the IV plane (bottom right plane)
 */
void	cub3d_render(t_cub3d *c)
{
	t_asset_manager	*am;

	am = &c->am;
	mlx_image_to_window(c->mlx, am->ceiling, 0, 0);
	mlx_image_to_window(c->mlx, am->floor, 0, HEIGHT / 2);
}