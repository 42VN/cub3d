/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:30:53 by hitran            #+#    #+#             */
/*   Updated: 2025/01/29 15:40:41 by hitran           ###   ########.fr       */
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

static void	load_png(t_cub3d *cub)
{
	cub->mini_images = ft_calloc(M_TEXTURE_NO + 1, sizeof(mlx_image_t));
	if (!cub->mini_images)
		game_error(cub, "Memory allocation failed");
	cub->mini_images[SPACE] = png_to_image(cub, M_SPACE);
	cub->mini_images[WALL] = png_to_image(cub, M_WALL);
	cub->mini_images[PLAYER] = png_to_image(cub, M_PLAYER);
}

static void	image_to_window(t_cub3d *cub, mlx_image_t *im,
	int32_t row, int32_t col)
{
	if (mlx_image_to_window(cub->mlx, im, col * MPX, row * MPX) < 0)
		game_error(cub, mlx_strerror(mlx_errno));
}

void	display_minimap(t_cub3d *cub, int32_t row, int32_t col)
{
	int	len;

	load_png(cub);
	while (++row < cub->map->max_rows)
	{
		col = -1;
		len = ft_strlen(cub->map->arr[row]);
		while (++col < len)
		{
			if (cub->map->arr[row][col] == '1')
				image_to_window(cub, cub->mini_images[WALL], row, col);
			else if (cub->map->arr[row][col] != ' ')
				image_to_window(cub, cub->mini_images[SPACE], row, col);
		}
	}
	image_to_window(cub, cub->mini_images[PLAYER], cub->current.row, cub->current.col);
}
