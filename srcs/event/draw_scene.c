/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:08:10 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/21 15:19:48 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_image(mlx_image_t *image)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	*pixels;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			pixels = (uint32_t *)(image->pixels + (y * image->width + x) * 4);
			*pixels = 0;
			x++;
		}
		y++;
	}
}

static void	copy_pixel(
	t_cub *cub,
	int32_t x,
	int32_t y_pixel,
	int32_t image_pos_y
)
{
	uint32_t	*dest_pixels;
	uint32_t	*src_pixels;

	if ((uint8_t)image_pos_y < cub->rays[x]->image->height - 1)
	{
		dest_pixels = (uint32_t *)ft_get_pixels(cub->am.scene, x, y_pixel);
		src_pixels = (uint32_t *)ft_get_pixels(cub->rays[x]->image,
				cub->rays[x]->im_position,
				image_pos_y);
		*(uint32_t *)dest_pixels = *(uint32_t *)src_pixels;
	}
	else
	{
		dest_pixels = (uint32_t *)ft_get_pixels(cub->am.scene, x, y_pixel);
		src_pixels = (uint32_t *)ft_get_pixels(cub->rays[x]->image,
				cub->rays[x]->im_position,
				cub->rays[x]->image->height - 1);
		*(uint32_t *)dest_pixels = *(uint32_t *)src_pixels;
	}
}

static void	draw_texture(t_cub *cub, int i, double wall_height,
double scale)
{
	double		texture_y;
	int32_t		image_pos_y;
	int32_t		start_y;
	double		texture_offset;

	texture_offset = 0;
	if (wall_height >= HEIGHT)
	{
		texture_offset = (wall_height - HEIGHT) / -1.0;
		wall_height = HEIGHT - 1;
	}
	start_y = HEIGHT / 2 - wall_height / 2;
	texture_y = (start_y - HEIGHT / 2 + wall_height / 2) * scale
		* texture_offset;
	while (wall_height > 0)
	{
		image_pos_y = (int)texture_y;
		texture_y += scale;
		copy_pixel(cub, i, start_y, image_pos_y);
		start_y++;
		wall_height--;
	}
}

void	draw_scene(t_cub *cub)
{
	int		i;
	double	wall_height;
	double	scale;
	double	camera_plane_dist;

	i = 0;
	camera_plane_dist = (WIDTH / 2) / tan(PI / 6);
	clear_image(cub->am.scene);
	while (i < WIDTH)
	{
		wall_height = (CELL_PX / cub->rays[i]->distance) * camera_plane_dist;
		scale = (double)cub->rays[i]->image->height / wall_height;
		draw_texture(cub, i, wall_height, scale);
		i++;
	}
}
