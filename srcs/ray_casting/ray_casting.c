/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:45:28 by hitran            #+#    #+#             */
/*   Updated: 2025/02/06 15:25:02 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_ray_angle(double angle, double index)
{
	double res;

	res = rescale(angle + (PI / 2 ) * (0.5 - index /(19 - 1)));
	return (res);
}

t_ray	*init_a_ray(t_cub *cub, int index)
{
	t_ray	*ray;

	ray = cub->rays + index;
	ray->start = (t_dpoint){cub->player.current.x + CELL_PX / 2,
							cub->player.current.y + CELL_PX / 2};
	ray->end = (t_dpoint){ray->start.x, ray->start.y};
	ray->angle = get_ray_angle(cub->player.angle, (double)index);
	ray->dir.x = cos(ray->angle);
	ray->dir.y = sin(ray->angle);
	return (ray);
}

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

void	ray_casting(t_cub *cub)
{
	t_ray	*ray;
	int		index;

	index = 0;
	// while (index < WIDTH)
	if (!cub || !cub->rays)
		return ;
	while (index < 18) //index < rays lenght
	{
		ray = init_a_ray(cub, index);
		dda(ray, cub);
		index++;
	}
}
