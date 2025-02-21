/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:37:29 by hitran            #+#    #+#             */
/*   Updated: 2025/02/21 14:59:13 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_vars(t_dpoint *distance, t_point *step, t_ray *ray)
{
	t_dpoint	cur;
	
	cur = (t_dpoint){fmod(ray->start.x, CELL_PX), fmod(ray->start.y, CELL_PX)};
	*distance = (t_dpoint){0, 0};
	*step = (t_point){1, 1};
	if (ray->dir.x > 0)
		distance->x = fabs((CELL_PX - cur.x) / ray->dir.x);
	else
	{
		distance->x = fabs(cur.x / ray->dir.x);
		step->col = -1;
	}
	if (ray->dir.y > 0)
	{
		distance->y = fabs(cur.y / ray->dir.y);
		step->row = -1;
	}
	else
		distance->y = fabs((CELL_PX - cur.y) / ray->dir.y);
}

void	find_hit_point(t_ray *ray, t_cub *cub)
{
	t_dpoint	distance;
	t_point		step;

	ray->hit = (t_point){ray->start.y / CELL_PX, ray->start.x / CELL_PX};
	init_vars(&distance, &step, ray);
	while (cub->map.grid[ray->hit.row][ray->hit.col] != '1'
			&& cub->map.grid[ray->hit.row][ray->hit.col] != 'D')
	{
		if (distance.x < distance.y)
		{
			distance.x += fabs(CELL_PX / ray->dir.x);
			ray->hit.col += step.col;
			ray->hit_direction = HORIZONTAL;
		}
		else
		{
			distance.y += fabs(CELL_PX / ray->dir.y);
			ray->hit.row += step.row;
			ray->hit_direction = VIRTICAL;
		}
	}
}
