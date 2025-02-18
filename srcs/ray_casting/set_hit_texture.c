/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:07:06 by hitran            #+#    #+#             */
/*   Updated: 2025/02/18 14:11:29 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_texture(t_ray *ray, mlx_image_t **image)
{
	if (ray->hit_direction == VIRTICAL)
	{
		ray->image = image[EA];
		if (ray->end.x < ray->start.x)
			ray->image = image[WE];
		ray->im_location = fmod(ray->end.y, CELL_PX);
	}
	else
	{
		ray->image = image[NO];
		if (ray->end.y > ray->start.y)
			ray->image = image[SO];
		ray->im_location = fmod(ray->end.x, CELL_PX);
	}
}

void	set_image(t_ray *ray, t_cub *cub)
{
	if (cub->map.grid[ray->hit.row][ray->hit.row] == 'D')
		set_texture(ray, cub->am.door);
	else if (cub->map.grid[ray->hit.row][ray->hit.row] == '1')
		set_texture(ray, cub->am.walls);
}
