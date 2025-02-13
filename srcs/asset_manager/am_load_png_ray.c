/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_load_png_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:48:24 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/13 11:56:45 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image_t	*am_load_png_ray(t_cub *c, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		cub3d_error_exit(c, (char *)mlx_strerror(mlx_errno));
	image = mlx_texture_to_image(c->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		cub3d_error_exit(c, (char *)mlx_strerror(mlx_errno));
	if (!mlx_resize_image(image, 4, 4)) // RAY CELL 4x4
		cub3d_error_exit(c, (char *)mlx_strerror(mlx_errno));
	return (image);
}
