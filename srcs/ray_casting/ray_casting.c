/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:45:28 by hitran            #+#    #+#             */
/*   Updated: 2025/02/04 10:14:05 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * DDA: Digital Differential Analyzer
 */
void	dda(t_ray *ray, t_cub *cub)
{
	find_hit_point(ray, cub);
	set_end_point(ray->hit.row, ray->hit.col, ray);
	ft_image_to_window(cub, cub->mini[RAY], cub->rays->end.x, cub->rays->end.y);
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
