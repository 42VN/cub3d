/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:00:31 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/20 16:59:32 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d_init(t_cub3d *c)
{
	t_asset_manager	*am;

	ft_bzero(c, sizeof(t_cub3d));
	am = &c->am;
	c->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!c->mlx)
	{
		cub3d_free(c);
		exit(EXIT_FAILURE);
	}
	// am->sprite_weapon = am_load_sprite(
	// 	cub->mlx,
	// 	(t_sprite){  }, "assets/sprites/weapons.png")
	return (1);
}
