/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:45:28 by hitran            #+#    #+#             */
/*   Updated: 2025/02/19 14:10:04 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	rescale(double angle)
{
	if (angle < 0)
		return (angle + 2 * PI);
	else if (angle >= 2 * PI)
		return (angle - 2 * PI);
	else
		return (angle);
}

double	get_ray_angle(double angle, double index)
{
	return (rescale(angle + (PI / 2 ) * (0.5 - index /(WIDTH - 1))));
}

void	init_a_ray(t_cub *cub, int index)
{
	cub->rays[index]->start = (t_dpoint){cub->player.current.x + CELL_PX / 2,
							cub->player.current.y + CELL_PX / 2};
	cub->rays[index]->end = (t_dpoint){cub->rays[index]->start.x,
										cub->rays[index]->start.y};
	cub->rays[index]->angle = get_ray_angle(cub->player.angle, (double)index);
	cub->rays[index]->dir = (t_dpoint){cos(cub->rays[index]->angle),
										sin(cub->rays[index]->angle)};
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
		init_a_ray(cub, index);
		find_hit_point(cub->rays[index], cub);
		process_ray_hit(cub->rays[index], cub);
	}
}
