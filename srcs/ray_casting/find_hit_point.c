/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:37:29 by hitran            #+#    #+#             */
/*   Updated: 2025/02/24 14:55:52 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_vars(t_dpoint *distance, t_point *step, t_ray *ray)
{
	t_dpoint	cur;
	
	cur = (t_dpoint){fmod(ray->start.x, CELL_PX), fmod(ray->start.y, CELL_PX)};
	*distance = (t_dpoint){DBL_MAX, DBL_MAX};
	*step = (t_point){1, 1};
	if (ray->dir.x > 0) // right direction
		distance->x = fabs((CELL_PX - cur.x) / ray->dir.x);
	else if (ray->dir.x < 0)// left direction
	{
		distance->x = fabs(cur.x / ray->dir.x);
		step->col = -1;
	}
	if (ray->dir.y > 0) //up direction
	{
		distance->y = fabs(cur.y / ray->dir.y);
		step->row = -1;
	}
	else if (ray->dir.y < 0)// down direction
		distance->y = fabs((CELL_PX - cur.y) / ray->dir.y);
}

/*
 * The `distance` variable represents the distance from the ray's starting point
 * to the next grid boundary along both the X and Y axes. It is used to  
 * determine which edge (horizontal or vertical) the ray will hit first.
 *
 * - distance.x: Distance to the next vertical grid line (left or right wall).
 * - distance.y: Distance to the next horizontal grid line (top or bottom wall).
 *
 * The ray advances by always moving in the direction of the smaller distance 
 * until it collides with a wall or a door ('1' or 'D') in the map.
 * 
 * - If distance.x < distance.y: the ray reaches the next vertical grid line 
 * first
 *
 * - If distance.y < distance.x: the ray reaches the next horizontal grid line 
 * first
 */
void	find_hit_point(t_ray *ray, t_cub *cub)
{
	t_dpoint	distance;
	t_point		step;

	// ray->hit = (t_point){ray->start.y / CELL_PX, ray->start.x / CELL_PX};
	init_vars(&distance, &step, ray);
	while (cub->map.grid[ray->hit.row][ray->hit.col] != '1'
			&& cub->map.grid[ray->hit.row][ray->hit.col] != 'D')
	{
		if (distance.x < distance.y) //hit the virtical line of the grid
		{
			distance.x += fabs(CELL_PX / ray->dir.x);
			ray->hit.col += step.col;
			ray->hit_direction = VERTICAL; //corrected
		}
		else //hit the horizontal line of the grid
		{
			distance.y += fabs(CELL_PX / ray->dir.y);
			ray->hit.row += step.row;
			ray->hit_direction = HORIZONTAL; //corrected
		}
	}
}
