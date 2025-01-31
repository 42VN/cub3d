/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_load_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:28:13 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 16:16:00 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

mlx_image_t	*am_load_png(t_cub *c, t_png_options options, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	if (!c->mlx || !path)
		cub3d_error_exit(c, "am_load_png: Invalid parameter(s)");
	texture = mlx_load_png(path);
	if (!texture)
		cub3d_error_exit(c, "am_load_png: mlx_load_png");
	image = mlx_texture_to_image(c->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		cub3d_error_exit(c, "am_load_png: mlx_texture_to_image");
	if (options.is_resized)
	{
		if (!mlx_resize_image(image, options.resized_px_x, options.resized_px_y))
			cub3d_error_exit(c, "am_load_png: mlx_resize_image");
	}
	return (image);
}
