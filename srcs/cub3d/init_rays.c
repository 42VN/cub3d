/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:01:18 by hitran            #+#    #+#             */
/*   Updated: 2025/02/03 13:09:00 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	init_ray(t_ray *ray, t_player player, int index)
// {
// 	ray->start = (t_dpoint){player.current.x + CELL_PX / 2,
// 							player.current.y + CELL_PX / 2};
// 	ray->end = (t_dpoint){ray->start.x, ray->start.y};
// 	ray->angle = get_ray_angle(player.angle, (double)index);
// 	ray->dir = (t_dpoint){cos(ray->angle), sin(ray->angle)};
// }

int	init_rays(t_ray **rays, t_player player)
{
	// int	index;

	// index = -1;
	// while (++index < WIDTH)
	// {
	// 	rays[index] = (t_ray *)ft_calloc(1, sizeof(t_ray));
	// 	if (!rays[index])
	// 		return (EXIT_FAILURE);
	// 	// init_ray(rays[index], player, index);
	// }
}
