/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:45:28 by hitran            #+#    #+#             */
/*   Updated: 2025/02/03 15:05:29 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * DDA: Digital Differential Analyzer
 */
void	dda(t_ray *ray, t_cub *cub)
{
	find_hit_point(ray, cub);
	ft_image_to_window(cub, cub->mini[RAY], cub->rays->hit.col * CELL_PX, cub->rays->hit.row * CELL_PX);
	// set_end_point(ray->hit.row, ray->hit.col, ray);
	// set_hit_texture(ray->hit.row, ray->hit.col, ray, cub);
	// set_distance(ray, cub);
}



double	get_ray_angle(double angle, int index)
{
	double res;

	res = rescale(angle + FOV * (0.5 - index /(WIDTH - 1)));
	return (res);
}

void	ray_casting(t_cub *cub)
{
	t_ray	*ray;
	int		index;

	index = 0;
	while (index < WIDTH)
	{
		ray = cub->rays + index;
		ray->start = (t_dpoint){cub->player.current.x + CELL_PX / 2, cub->player.current.y + CELL_PX / 2};
		ray->end = (t_dpoint){ray->start.x, ray->start.y};
		ray->angle = get_ray_angle(cub->player.angle, index);
		ray->dir.x = cos(ray->angle);
		ray->dir.y = sin(ray->angle);
		dda(ray, cub);
		index++;
	}
}
