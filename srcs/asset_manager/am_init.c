/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:28:06 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/05 13:52:41 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_manager.h"
#include "cub3d.h"

static void	init_img(t_cub *c, mlx_image_t **img, uint32_t width, uint32_t height)
{
	*img = mlx_new_image(c->mlx, width, height);
	if (!*img)
		cub3d_error_exit(c, "am_init: mlx_new_image");
}

void	am_init(t_cub *c)
{
	t_asset_manager	*am;

	am = &c->am;
	am->sprite_weapon = am_load_sprite(c,
		(t_sprite_options){1, 6, 0, DIR_VERTICAL},
		(t_png_options){0, 0, 0},
		"./assets/sprites/weapons.png");
		
	am->m_wall = am_load_png(c, (t_png_options){1, M_PX, M_PX}, M_WALL);
	am->m_player = am_load_png(c, (t_png_options){1, M_PX, M_PX}, M_PLAYER);
	am->m_player = am_load_png(c, (t_png_options){1, M_PX, M_PX}, M_SPACE);

	init_img(c, &am->ceiling, WIDTH, HEIGHT / 2);
	init_img(c, &am->floor, WIDTH, HEIGHT / 2);
	init_img(c, &am->m_map, M_WIDTH, M_HEIGHT);
	init_img(c, &am->m_map_bg, M_WIDTH, M_HEIGHT);

	printf("Color: %u\n",(unsigned int) c->map.c_color);

	if (!ft_fill_color_int(am->ceiling, c->map.c_color)
		|| !ft_fill_color_int(am->floor, c->map.f_color)
		|| !ft_fill_color(am->m_map, (t_color){45, 52, 54, 255})
		|| !ft_fill_color(am->m_map_bg, (t_color){45, 52, 54, 255})
	)
	{
		cub3d_error_exit(c, "ft_fill_color");
	}
}
