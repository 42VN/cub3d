/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:45:28 by hitran            #+#    #+#             */
/*   Updated: 2025/02/04 11:57:53 by hitran           ###   ########.fr       */
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
	// ft_image_to_window(cub, cub->mini[RAY], cub->rays->end.x, cub->rays->end.y);
	// set_hit_texture(ray->hit.row, ray->hit.col, ray, cub);
	// set_distance(ray, cub);
}

double	get_ray_angle(double angle, double index)
{
	double res;

	res = rescale(angle + (PI / 2 ) * (0.5 - index /(19 - 1)));
	return (res);
}

/*
i = 0 -> pi/2 * 1/2 = pi/4
i = 1 -> pi/2 *( 1/2 - 1/18)
*/
void	ray_casting(t_cub *cub)
{
	t_ray	*ray;
	int		index;

	index = 0;
	// while (index < WIDTH)
	while (index < 18)
	{
		// printf("index = %d\n", index);
		ray = cub->rays + index;
		ray->start = (t_dpoint){cub->player.current.x + CELL_PX / 2, cub->player.current.y + CELL_PX / 2};
		ray->end = (t_dpoint){ray->start.x, ray->start.y};
		ray->angle = get_ray_angle(cub->player.angle, (double)index);
		ray->dir.x = cos(ray->angle);
		ray->dir.y = sin(ray->angle);
		// printf("index = %d, angle = %f, dir x  = %f, dir y = %f\n", index, ray->angle, ray->dir.x, ray->dir.y);
		dda(ray, cub);
		// printf("Ray %d: Hit at (row = %d, col = %d)\n", index, ray->hit.row, ray->hit.col);	
		// printf("Ray %d: End at (%.2f, %.2f)\n", index, ray->end.x, ray->end.y);
		ft_image_to_window(cub, cub->mini[RAY], (int32_t)ray->end.x, (int32_t)ray->end.y);
		index++;
	}
}
