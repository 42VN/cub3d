/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_load_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:29:36 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/16 17:48:47 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_manager.h"

mlx_image_t	*am_load_png(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	
	if (!mlx || !path)
		return (ft_error_ret("am_load_png: Invalid parameter(s)", 0));
	texture = mlx_load_png(path);
	if (!texture)
		return (ft_error_ret("mlx_load_png", 0));
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		return (ft_error_ret("mlx_texture_to_image", 0));
	return (img);
}
