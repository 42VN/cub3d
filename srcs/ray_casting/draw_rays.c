/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:16:38 by hitran            #+#    #+#             */
/*   Updated: 2025/02/13 14:56:06 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ray(t_ray *ray, t_cub *cub)
{
	double dx = ray->end.x - ray->start.x;
    double dy = ray->end.y - ray->start.y;
    double steps = fmax(fabs(dx), fabs(dy)) / 4;

    double x_inc = dx / steps;
    double y_inc = dy / steps;

    double x = ray->start.x;
    double y = ray->start.y;
	
	for (int i = 0; i < steps; i++)
	{
		ft_image_to_window(cub, cub->mini[RAY], (int32_t)x, (int32_t)y);
		x += x_inc;
		y += y_inc;
	}
}

void	draw_rays(t_cub *cub)
{
	int index = 0;

	while (index < WIDTH)
	{
		draw_ray(&cub->rays[index], cub);
		index += WIDTH/18;
	}
}