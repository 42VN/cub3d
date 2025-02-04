/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:45:28 by hitran            #+#    #+#             */
/*   Updated: 2025/02/04 12:15:26 by hitran           ###   ########.fr       */
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
	// set_hit_texture(ray->hit.row, ray->hit.col, ray, cub);
	// set_distance(ray, cub);
}

double	get_ray_angle(double angle, double index)
{
	double res;

	res = rescale(angle + (PI / 2 ) * (0.5 - index /(19 - 1)));
	return (res);
}

void	ray_casting(t_cub *cub)
{
	t_ray	*ray;
	int		index;

	index = 0;
	// while (index < WIDTH)
	while (index < 18)
	{
		ray = cub->rays + index;
		ray->start = (t_dpoint){cub->player.current.x + CELL_PX / 2, cub->player.current.y + CELL_PX / 2};
		ray->end = (t_dpoint){ray->start.x, ray->start.y};
		ray->angle = get_ray_angle(cub->player.angle, (double)index);
		ray->dir.x = cos(ray->angle);
		ray->dir.y = sin(ray->angle);
		dda(ray, cub);
		index++;
	}
}
