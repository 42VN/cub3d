/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_load_png_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:48:24 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/21 15:06:18 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_error(t_cub *c, char *str, const char *path)
{
	ft_error(str);
	if (path)
		ft_printf_fd(2, "[Path: %s]\n", path);
	exit(1);
}

mlx_image_t	*am_load_png_ray(t_cub *c, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		load_error(c, (char *)mlx_strerror(mlx_errno), path);
	image = mlx_texture_to_image(c->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		load_error(c, (char *)mlx_strerror(mlx_errno), path);
	if (!mlx_resize_image(image, 4, 4))
		load_error(c, (char *)mlx_strerror(mlx_errno), path);
	return (image);
}
