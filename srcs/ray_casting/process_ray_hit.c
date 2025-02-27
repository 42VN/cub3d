/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ray_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:14:46 by hitran            #+#    #+#             */
/*   Updated: 2025/02/27 14:13:48 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Determines the intersection point of the ray with a vertical wall.
 * Calculates ray->end.x as the vertical grid line at ray->hit.col. Then adjusts
 * for leftward movement by setting the right edge of the cell.
 * Calculates delta_x as the distance from the starting point to the end point.
 * Uses tan(ray->angle) to compute delta_y (the distance along the Y-axis).
 */
static void	set_vertical_end(t_ray *ray)
{
	double	delta_x;
	double	delta_y;

	ray->end.x = ray->hit.col * CELL_PX;
	if (ray->end.x < ray->start.x)
		ray->end.x += CELL_PX;
	delta_x = ray->end.x - ray->start.x;
	delta_y = fabs(delta_x * tan(ray->angle));
	if (ray->dir.y > 0)
		ray->end.y = ray->start.y - delta_y;
	else
		ray->end.y = ray->start.y + delta_y;
}

static void	set_vertical_image(t_ray *ray, t_cub *cub)
{
	if (ray->end.x > ray->start.x)
		ray->image = cub->am.walls[WE];
	else
		ray->image = cub->am.walls[EA];
	ray->im_position = fmod(ray->end.y, CELL_PX) * ray->image->width / CELL_PX;
}

static void	set_horizontal_end(t_ray *ray)
{
	double	delta_x;
	double	delta_y;

	ray->end.y = ray->hit.row * CELL_PX;
	if (ray->end.y < ray->start.y)
		ray->end.y += CELL_PX;
	delta_y = ray->end.y - ray->start.y;
	delta_x = fabs(delta_y / tan(ray->angle));
	if (ray->dir.x > 0)
		ray->end.x = ray->start.x + delta_x;
	else
		ray->end.x = ray->start.x - delta_x;
}

static void	set_horizontal_image(t_ray *ray, t_cub *cub)
{
	if (ray->end.y < ray->start.y)
		ray->image = cub->am.walls[SO];
	else
		ray->image = cub->am.walls[NO];
	ray->im_position = fmod(ray->end.x, CELL_PX) * ray->image->width / CELL_PX;
}

void	process_ray_hit(t_ray *ray, t_cub *cub)
{
	if (ray->hit_direction == VERTICAL)
	{
		set_vertical_end(ray);
		set_vertical_image(ray, cub);
	}
	else
	{
		set_horizontal_end(ray);
		set_horizontal_image(ray, cub);
	}
	if (fpclassify(ray->dir.x) == FP_ZERO)
		ray->distance = fabs(ray->end.y - ray->start.y);
	else
		ray->distance = fabs((ray->end.x - ray->start.x) / ray->dir.x);
	ray->distance *= fabs(cos(rescale(cub->player.angle - ray->angle)));
}
