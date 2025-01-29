/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:30:53 by hitran            #+#    #+#             */
/*   Updated: 2025/01/29 12:33:38 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_image_t	*png_to_image(t_cub3d *cub, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		game_error(cub, mlx_strerror(mlx_errno));
	image = mlx_texture_to_image(cub->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		game_error(cub, mlx_strerror(mlx_errno));
	if (!mlx_resize_image(image, MPX, MPX))
		game_error(cub, mlx_strerror(mlx_errno));
	return (image);
}

void	load_png(t_cub3d *cub)
{
	cub->mini_images = ft_calloc(M_TEXTURE_NO + 1, sizeof(mlx_image_t));
	if (!cub->mini_images)
		game_error(cub, "Memory allocation failed");
	cub->mini_images[EMPTY] = png_to_image(cub, M_EMPTY);
	cub->mini_images[SPACE] = png_to_image(cub, M_SPACE);
	cub->mini_images[WALL] = png_to_image(cub, M_WALL);
	cub->mini_images[PLAYER] = png_to_image(cub, M_PLAYER);
}
