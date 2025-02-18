/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:07:13 by hitran            #+#    #+#             */
/*   Updated: 2025/02/18 13:34:58 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_distance(t_ray *ray, t_cub *cub)
{
	if (fabs(ray->dir.x - 0.0) < 1e-9)
		ray->distance = fabs((ray->end.y - ray->start.y) / ray->dir.y);
	else
		ray->distance = fabs((ray->end.x - ray->start.x) / ray->dir.x);
	ray->distance *= fabs(cos(rescale(cub->player.angle - ray->angle)));
}
