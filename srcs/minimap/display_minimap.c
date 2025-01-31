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

// #include "cub3d.h"

// static mlx_image_t	*png_to_image(t_cub *cub, const char *path)
// {
// 	mlx_texture_t	*texture;
// 	mlx_image_t		*image;

// 	texture = mlx_load_png(path);
// 	if (!texture)
// 		game_error(cub, mlx_strerror(mlx_errno));
// 	image = mlx_texture_to_image(cub->mlx, texture);
// 	mlx_delete_texture(texture);
// 	if (!image)
// 		game_error(cub, mlx_strerror(mlx_errno));
// 	if (!mlx_resize_image(image, MPX, MPX))
// 		game_error(cub, mlx_strerror(mlx_errno));
// 	return (image);
// }

// static void	load_png(t_cub *cub)
// {
// 	cub->m_images = ft_calloc(M_TEXTURE_NO + 1, sizeof(mlx_image_t));
// 	if (!cub->m_images)
// 		game_error(cub, "Memory allocation failed");
// 	cub->m_images[SPACE] = png_to_image(cub, M_SPACE);
// 	cub->m_images[WALL] = png_to_image(cub, M_WALL);
// 	cub->m_images[PLAYER] = png_to_image(cub, M_PLAYER);
// }

// static void	ft_image_to_window(t_cub *cub, mlx_image_t *im,
// 	int32_t x, int32_t y)
// {
// 	if (mlx_image_to_window(cub->mlx, im, x * MPX, y * MPX) < 0)
// 		game_error(cub, mlx_strerror(mlx_errno));
// }

// void	display_minimap(t_cub *cub, int32_t y, int32_t x)
// {
// 	int	len;

// 	load_png(cub);
// 	while (++y < cub->map->max_rows)
// 	{
// 		x = -1;
// 		len = ft_strlen(cub->map->grid[y]);
// 		while (++x < len)
// 		{
// 			if (cub->map->grid[y][x] == '1')
// 				ft_image_to_window(cub, cub->m_images[WALL], x, y);
// 			else if (cub->map->grid[y][x] != ' ')
// 				ft_image_to_window(cub, cub->m_images[SPACE], x, y);
// 		}
// 	}
// 	ft_image_to_window(cub, cub->m_images[PLAYER], cub->current.x, cub->current.y);
// }
