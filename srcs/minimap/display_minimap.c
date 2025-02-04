// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   display_minimap.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/20 00:30:53 by hitran            #+#    #+#             */
// /*   Updated: 2025/01/31 10:51:47 by hitran           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3d.h"

static mlx_image_t	*png_to_image(t_cub *cub, const char *path)
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

mlx_image_t	*png_to_ray(t_cub *cub, const char *path)
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
	if (!mlx_resize_image(image, 4, 4)) // RAY CELL 4x4
		game_error(cub, mlx_strerror(mlx_errno));
	return (image);
}

static void	load_png(t_cub *cub)
{
	cub->mini = ft_calloc(M_TEXTURE_NO + 1, sizeof(mlx_image_t *));
	if (!cub->mini)
		game_error(cub, "Memory allocation failed");
	cub->mini[SPACE] = png_to_image(cub, M_SPACE);
	cub->mini[WALL] = png_to_image(cub, M_WALL);
	cub->mini[PLAYER] = png_to_image(cub, M_PLAYER);
	cub->mini[RAY] = png_to_ray(cub, M_RAY);
}

// static void	ft_image_to_window(t_cub *cub, mlx_image_t *im,
// 	int32_t x, int32_t y)
// {
// 	if (mlx_image_to_window(cub->mlx, im, x, y) < 0)
// 		game_error(cub, mlx_strerror(mlx_errno));
// }

void	display_minimap(t_cub *cub, int32_t row, int32_t col)
{
	int	len;

	load_png(cub);
	while (++row < cub->map.max_rows)
	{
		col = -1;
		len = ft_strlen(cub->map.grid[row]);
		while (++col < len)
		{
			if (cub->map.grid[row][col] == '1')
				ft_image_to_window(cub, cub->mini[WALL], col * CELL_PX, row * CELL_PX);
			else if (cub->map.grid[row][col] == '0')
				ft_image_to_window(cub, cub->mini[SPACE], col * CELL_PX, row * CELL_PX);
		}
	}
	ft_image_to_window(cub, cub->mini[PLAYER], cub->player.current.x, cub->player.current.y);
}
