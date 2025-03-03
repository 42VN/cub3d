/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:28:06 by ktieu             #+#    #+#             */
/*   Updated: 2025/03/03 09:29:58 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_manager.h"
#include "cub3d.h"

static int	ft_fill_map_ele(t_cub *c, mlx_image_t *map_img, char ele)
{
	if (ele == '1')
	{
		if (!ft_copy_pixels(map_img, c->am.m_wall, M_PX, M_PX))
			return (ft_error(
					"am_init: init_img: ft_fill_map: ft_copy_pixels"), 0);
	}
	return (1);
}

static int	ft_fill_map(t_cub *c, mlx_image_t *map_img, char **grid)
{
	uint8_t *const	original = map_img->pixels;
	int32_t			row;
	int32_t			col;

	row = 0;
	while (row < c->map.max_rows)
	{
		col = 0;
		while (col < c->map.max_cols)
		{
			map_img->pixels = ft_get_pixels(map_img, col * M_PX, row * M_PX);
			if (!map_img->pixels)
				return (ft_error(
						"am_init: init_img: ft_fill_map: ft_get_pixels"), 0);
			ft_fill_map_ele(c, map_img, grid[row][col]);
			map_img->pixels = original;
			col++;
		}
		row++;
	}
	return (1);
}

static void	init_img(
	t_cub *c,
	mlx_image_t **img,
	uint32_t width,
	uint32_t height)
{
	*img = mlx_new_image(c->mlx, width, height);
	if (!*img)
		cub3d_error_exit(c, "am_init: mlx_new_image");
}

static void	init_imgs(t_cub *c, t_asset_manager *am)
{
	init_img(c, &am->player,
		am->sprite_weapon->frame_w, am->sprite_weapon->frame_h);
	init_img(c, &am->ceiling, WIDTH, HEIGHT / 2);
	init_img(c, &am->floor, WIDTH, HEIGHT / 2);
	init_img(c, &am->scene, WIDTH, HEIGHT);
	init_img(c, &am->map, c->map.width, c->map.height);
	init_img(c, &am->m_map, M_WIDTH, M_HEIGHT);
	init_img(c, &am->m_map_bg, M_WIDTH, M_HEIGHT);
	am->walls[NO] = am_load_png(c,
			(t_png_options){0, CELL_PX, CELL_PX}, c->map.no_path);
	am->walls[SO] = am_load_png(c,
			(t_png_options){0, CELL_PX, CELL_PX}, c->map.so_path);
	am->walls[EA] = am_load_png(c,
			(t_png_options){0, CELL_PX, CELL_PX}, c->map.ea_path);
	am->walls[WE] = am_load_png(c,
			(t_png_options){0, CELL_PX, CELL_PX}, c->map.we_path);
	if (!ft_fill_color_int(am->ceiling, c->map.c_color)
		|| !ft_fill_color_int(am->floor, c->map.f_color)
		|| !ft_fill_color(am->m_map_bg, (t_color){45, 52, 54, 255})
		|| !ft_fill_map(c, am->map, c->map.grid)
	)
		cub3d_error_exit(c, "ft_fill_color");
}

void	am_init(t_cub *c)
{
	t_asset_manager	*am;

	am = &c->am;
	am->sprite_weapon = am_load_sprite(c,
			(t_sprite_options){4, 6, 1, DIR_VERTICAL, 0},
			(t_png_options){0, 0, 0},
			"./assets/sprites/weapon2.png");
	am->m_wall = am_load_png(c, (t_png_options){1, M_PX, M_PX}, M_WALL);
	am->m_player = am_load_png(c,
			(t_png_options){1, M_PLAYER_SIZE, M_PLAYER_SIZE}, M_PLAYER);
	am->m_space = am_load_png(c, (t_png_options){1, M_PX, M_PX}, M_SPACE);
	init_imgs(c, am);
}
