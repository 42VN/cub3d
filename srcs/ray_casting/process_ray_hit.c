/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ray_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:14:46 by hitran            #+#    #+#             */
/*   Updated: 2025/02/19 14:22:30 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	horizontal_hit(t_ray *ray, t_cub *cub)
{
	double	dy;

	ray->end.x = ray->hit.col * CELL_PX;
	if (ray->end.x < ray->start.x)
		ray->end.x += CELL_PX;
	dy = fabs((ray->end.x - ray->start.x) * ray->dir.y / ray->dir.x);
	if (ray->dir.y > 0)
		ray->end.y = ray->start.y - dy;
	else
		ray->end.y = ray->start.y + dy;
	if (cub->map.grid[ray->hit.row][ray->hit.row] == 'D')
		ray->image = cub->am.door;
	else //if (cub->map.grid[ray->hit.row][ray->hit.row] == '1')
	{
		if (ray->end.y < ray->start.y)
			ray->image = cub->am.walls[NO];
		else
			ray->image = cub->am.walls[SO];
	}
	ray->im_position = fmod(ray->end.x, CELL_PX);
}

static void	vertical_hit(t_ray *ray, t_cub *cub)
{
	double	dx;

	ray->end.y = ray->hit.row * CELL_PX;
	if (ray->end.y < ray->start.y)
		ray->end.y += CELL_PX;
	dx = fabs((ray->end.y - ray->start.y) * ray->dir.x / ray->dir.y);
	if (ray->dir.x > 0)
		ray->end.x = ray->start.x + dx;
	else
		ray->end.x = ray->start.x - dx;
	if (cub->map.grid[ray->hit.row][ray->hit.row] == 'D')
		ray->image = cub->am.door;
	else //if (cub->map.grid[ray->hit.row][ray->hit.row] == '1')
	{
		if (ray->end.x > ray->start.x)
			ray->image = cub->am.walls[EA];
		else
			ray->image = cub->am.walls[WE];
	}
	ray->im_position = fmod(ray->end.y, CELL_PX);
}

void	calculate_distance(t_ray *ray, t_cub *cub)
{
	if (fabs(ray->dir.x - 0.0) < 1e-9)
		ray->distance = fabs((ray->end.y - ray->start.y) / ray->dir.y);
	else
		ray->distance = fabs((ray->end.x - ray->start.x) / ray->dir.x);
	ray->distance *= fabs(cos(rescale(cub->player.angle - ray->angle)));
}

void	process_ray_hit(t_ray *ray, t_cub *cub)
{
	if (ray->hit_direction == VIRTICAL)
		vertical_hit(ray, cub);
	else
		horizontal_hit(ray, cub);
	if (!ray->image)
		printf("image\n");
	calculate_distance(ray, cub);
}
