/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ray_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:14:46 by hitran            #+#    #+#             */
/*   Updated: 2025/02/24 14:48:11 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_vertical_end(t_ray *ray) //vertical
{
	double	dy;

	ray->end.x = ray->hit.col * CELL_PX;
	if (ray->end.x < ray->start.x) //left direction
		ray->end.x += CELL_PX; // set the right edge
	dy = fabs((ray->end.x - ray->start.x) * ray->dir.y / ray->dir.x);
	if (ray->dir.y > 0) //up
		ray->end.y = ray->start.y - dy;
	else
		ray->end.y = ray->start.y + dy;
	// if (ray->end.y < 0)
	// 	ray->end.y = 0;
}

static void	set_vertical_image(t_ray *ray, t_cub *cub)
{
	if (cub->map.grid[ray->hit.row][ray->hit.col] == 'D')
		ray->image = cub->am.door;
	else
	{
		if (ray->end.x > ray->start.x) //right direction
			ray->image = cub->am.walls[WE];
		else //left direction
			ray->image = cub->am.walls[EA];
	}
	ray->im_position = fmod(ray->end.y, CELL_PX) * ray->image->width/CELL_PX;
}

static void	set_horizontal_end(t_ray *ray) //horizontal
{
	double	dx;

	ray->end.y = ray->hit.row * CELL_PX;
	if (ray->end.y < ray->start.y) //up direction
		ray->end.y += CELL_PX; //set the lower edge
	dx = fabs((ray->end.y - ray->start.y) * ray->dir.x / ray->dir.y);
	if (ray->dir.x > 0)
		ray->end.x = ray->start.x + dx;
	else
		ray->end.x = ray->start.x - dx;
	if (ray->end.x < 0)
		ray->end.x = 0;
}

static void	set_horizontal_image(t_ray *ray, t_cub *cub)
{
	if (cub->map.grid[ray->hit.row][ray->hit.col] == 'D')
		ray->image = cub->am.door;
	else
	{
		if (ray->end.y < ray->start.y)
			ray->image = cub->am.walls[SO];
		else
			ray->image = cub->am.walls[NO];
	}
	ray->im_position = fmod(ray->end.x, CELL_PX) * ray->image->width/CELL_PX;
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
		set_horizontal_image(ray,cub);
	}
	// printf("im_pos = %d\n", ray->im_position);
	if (fabs(ray->dir.x - 0.0) < 1e-9)
		ray->distance = fabs((ray->end.y - ray->start.y) / ray->dir.y);
	else
		ray->distance = fabs((ray->end.x - ray->start.x) / ray->dir.x);
	ray->distance *= fabs(cos(rescale(cub->player.angle - ray->angle)));
}
