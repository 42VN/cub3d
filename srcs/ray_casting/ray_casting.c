/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:45:28 by hitran            #+#    #+#             */
/*   Updated: 2025/02/18 14:09:18 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_ray_angle(double angle, double index)
{
	return (rescale(angle + (PI / 2 ) * (0.5 - index /(WIDTH - 1))));
}

t_ray	*init_a_ray(t_cub *cub, int index)
{
	t_ray	*ray;

	ray = cub->rays + index;
	ray->start = (t_dpoint){cub->player.current.x + CELL_PX / 2,
							cub->player.current.y + CELL_PX / 2};
	ray->end = (t_dpoint){ray->start.x, ray->start.y};
	ray->angle = get_ray_angle(cub->player.angle, (double)index);
	ray->dir = (t_dpoint){cos(ray->angle), sin(ray->angle)};
	return (ray);
}

void	ray_casting(t_cub *cub)
{
	t_ray	*ray;
	int		index;

	index = -1;
	if (!cub || !cub->rays)
		return ;
	while (++index < WIDTH)
	{
		ray = init_a_ray(cub, index);
		find_hit_point(ray, cub);
		process_ray_hit(ray, cub);
	}
}
