/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_load_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:28:13 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/23 17:22:59 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "asset_manager.h"

mlx_image_t	*am_load_png(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	
	if (!mlx || !path)
	{
		ft_error("am_load_png: Invalid parameter(s)");
		return (NULL);
	}
	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_error("am_load_png: mlx_load_png");
		return (NULL);
	}
	img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (img);
}
