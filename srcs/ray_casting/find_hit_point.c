/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:37:29 by hitran            #+#    #+#             */
/*   Updated: 2025/02/25 10:47:12 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Initializes the distance and step values for raycasting.
 * - cur: Position within the current grid cell.
 * - distance->to_vertical_line: Distance to the next vertical grid line.
 * - distance->to_horizontal_line: Distance to the next horizontal grid line.
 * - step->col: Direction of movement in the x-axis (1 for right, -1 for left).
 * - step->row: Direction of movement in the y-axis (1 for down, -1 for up).
 * Ensures correct stepping and distance calculations for detecting wall hits.
 * - ray->dir.x > 0: right direction
 * - ray->dir.y > 0: up direction
 */
static void	init_vars(t_distance *distance, t_point *step, t_ray *ray)
{
	t_dpoint	cur;
	
	cur = (t_dpoint){fmod(ray->start.x, CELL_PX), fmod(ray->start.y, CELL_PX)};
	*distance = (t_distance){DBL_MAX, DBL_MAX};
	*step = (t_point){1, 1};
	if (ray->dir.x > 0)
		distance->to_vertical_line = fabs((CELL_PX - cur.x) / ray->dir.x);
	else if (ray->dir.x < 0)
	{
		distance->to_vertical_line = fabs(cur.x / ray->dir.x);
		step->col = -1;
	}
	if (ray->dir.y > 0)
	{
		distance->to_horizontal_line = fabs(cur.y / ray->dir.y);
		step->row = -1;
	}
	else if (ray->dir.y < 0)
		distance->to_horizontal_line = fabs((CELL_PX - cur.y) / ray->dir.y);
}

/*
 * The distance variable represents the distance from the ray's starting point
 * to the next grid boundary along both the X and Y axes. It is used to  
 * determine which edge (horizontal or vertical) the ray will hit first.
 *
 * The ray advances by always moving in the direction of the smaller distance 
 * until it collides with a wall or a door ('1' or 'D') in the map.
 */
void	find_hit_point(t_ray *ray, t_cub *cub)
{
	t_distance	distance;
	t_point		step;

	init_vars(&distance, &step, ray);
	while (cub->map.grid[ray->hit.row][ray->hit.col] != '1'
			&& cub->map.grid[ray->hit.row][ray->hit.col] != 'D')
	{
		if (distance.to_vertical_line < distance.to_horizontal_line)
		{
			distance.to_vertical_line += fabs(CELL_PX / ray->dir.x);
			ray->hit.col += step.col;
			ray->hit_direction = VERTICAL;
		}
		else
		{
			distance.to_horizontal_line += fabs(CELL_PX / ray->dir.y);
			ray->hit.row += step.row;
			ray->hit_direction = HORIZONTAL;
		}
	}
}
