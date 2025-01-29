/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:30:53 by hitran            #+#    #+#             */
/*   Updated: 2025/01/29 13:49:50 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	image_to_window(t_cub3d *cub, mlx_image_t *im,
	int32_t row, int32_t col)
{
	if (mlx_image_to_window(cub->mlx, im, col * MPX, row * MPX) < 0)
		game_error(cub, mlx_strerror(mlx_errno));
}

void	display_minimap(t_cub3d *cub, int32_t row, int32_t col)
{
	int	len;

	while (++row < cub->map->max_rows)
	{
		col = -1;
		len = ft_strlen(cub->map->arr[row]);
		while (++col < len)
		{
			if (cub->map->arr[row][col] == '1')
				image_to_window(cub, cub->mini_images[WALL], row, col);
			else if (cub->map->arr[row][col] == ' ')
				image_to_window(cub, cub->mini_images[EMPTY], row, col);
			else
				image_to_window(cub, cub->mini_images[SPACE], row, col);		}
	}
	image_to_window(cub, cub->mini_images[PLAYER], cub->current.row, cub->current.col);
}
