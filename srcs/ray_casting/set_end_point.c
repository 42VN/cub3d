/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_end_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:14:46 by hitran            #+#    #+#             */
/*   Updated: 2025/02/04 10:14:51 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	horizontal_hit(int32_t col, t_ray *ray)
{
	double	dy;

	ray->end.x = col * CELL_PX;
	if (ray->end.x < ray->start.x)
		ray->end.x += CELL_PX;
	dy = fabs((ray->end.x - ray->start.x) * ray->dir.y / ray->dir.x);
	if (ray->dir.y > 0)
		ray->end.y = ray->start.y - dy;
	else
		ray->end.y = ray->start.y + dy;
}

static void	vertical_hit(int32_t row, t_ray *ray)
{
	double	dx;

	ray->end.y = row * CELL_PX;
	if (ray->end.y < ray->start.y)
		ray->end.y += CELL_PX;
	dx = fabs((ray->end.y - ray->start.y) * ray->dir.x / ray->dir.y);
	if (ray->dir.x > 0)
		ray->end.x = ray->start.x + dx;
	else
		ray->end.x = ray->start.x - dx;
}

void	set_end_point(int32_t row, int32_t col, t_ray *ray)
{
	if (ray->v_hit == true)
		vertical_hit(row, ray);
	else
		horizontal_hit(col, ray);
}
