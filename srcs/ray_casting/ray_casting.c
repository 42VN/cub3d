/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:45:28 by hitran            #+#    #+#             */
/*   Updated: 2025/02/26 15:19:19 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	rescale(double angle)
{
	if (angle < 0)
		return (angle + 2 * PI);
	else if (angle >= 2 * PI)
		return (angle - 2 * PI);
	else
		return (angle);
}

static double	get_ray_angle(double angle, double index)
{
	return (rescale(angle + (PI / 3) * (0.5 - index / (WIDTH - 1))));
}

static void	init_ray(t_ray *ray, t_player player, int index)
{
	int	os;

	os = M_PLAYER_SIZE / 2;
	ray->angle = get_ray_angle(player.angle, (double)index);
	ray->dir = (t_dpoint){cos(ray->angle), sin(ray->angle)};
	ray->start = (t_dpoint){player.current.x + os, player.current.y + os};
	ray->end = (t_dpoint){ray->start.x, ray->start.y};
	ray->hit = (t_point){ray->start.y / CELL_PX, ray->start.x / CELL_PX};
}

void	ray_casting(t_cub *cub)
{
	t_ray	*ray;
	int		index;

	index = -1;
	if (!cub || !cub->rays)
		return ;
	while (++index < WIDTH)
	{
		ft_bzero(cub->rays[index], sizeof(t_ray));
		init_ray(cub->rays[index], cub->player, index);
		find_hit_point(cub->rays[index], cub);
		process_ray_hit(cub->rays[index], cub);
	}
}
