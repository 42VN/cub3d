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

void	init_ray(t_ray *rays, t_player player)
{
	rays->start = (t_dpoint){player.current.x, player.current.y};
	rays->end = (t_dpoint){player.current.x, player.current.y};
	rays->angle = rescale(player.angle);
	rays->dir = (t_dpoint){cos(rays->angle), sin(rays->angle)};
	rays->hit = (t_point){-1, -1};
	rays->distance = 0;
}
