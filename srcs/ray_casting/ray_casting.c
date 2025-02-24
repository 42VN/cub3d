/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:45:28 by hitran            #+#    #+#             */
/*   Updated: 2025/02/24 14:48:56 by hitran           ###   ########.fr       */
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
	return (rescale(angle + (PI / 3 ) * (0.5 - index /(WIDTH - 1))));
}

void	init_a_ray(t_cub *cub, int index)
{
	if (cub->player.current.x < 0 || cub->player.current.x > cub->map.max_cols*CELL_PX
		|| cub->player.current.y < 0 || cub->player.current.y > cub->map.max_rows *CELL_PX)
	{
		printf("out of boundary\n");
		exit(1);
	}
	cub->rays[index]->start = (t_dpoint){cub->player.current.x + CELL_PX / 2,
							cub->player.current.y + CELL_PX / 2};
	cub->rays[index]->end = (t_dpoint){cub->rays[index]->start.x,
										cub->rays[index]->start.y};
	cub->rays[index]->hit = (t_point){cub->rays[index]->start.y / CELL_PX,
										cub->rays[index]->start.x / CELL_PX};
	cub->rays[index]->angle = get_ray_angle(cub->player.angle, (double)index);
	// printf("angle = %f\n", cub->rays[index]->angle);
	cub->rays[index]->dir = (t_dpoint){cos(cub->rays[index]->angle),
										sin(cub->rays[index]->angle)};
	cub->rays[index]->distance = 0;
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
		// printf("end.x =%f, end.y =%f, i = %d, pos = %d\n",cub->rays[index]->end.x, cub->rays[index]->end.y, index, cub->rays[index]->im_position);
	}
}
