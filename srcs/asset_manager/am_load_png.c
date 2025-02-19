/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_load_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:28:13 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/19 14:12:38 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static void	load_error(t_cub *c, char *str, const char *path)
{
	ft_error(str);
	if (path)
		ft_printf_fd(2, "[Path: %s]\n",path);
	exit(1);
}

mlx_image_t	*am_load_png(t_cub *c, t_png_options options, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	if (!c->mlx || !path)
		load_error(c, "am_load_png: Invalid parameter(s)", NULL);
	texture = mlx_load_png(path);
	if (!texture)
		load_error(c, "am_load_png: mlx_load_png", path);
	image = mlx_texture_to_image(c->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		load_error(c, "am_load_png: mlx_texture_to_image", path);
	if (options.is_resized)
	{
		if (!mlx_resize_image(image, options.resized_px_x, options.resized_px_y))
			load_error(c, "am_load_png: mlx_resize_image", path);
	}
	return (image);
}
