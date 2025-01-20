/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:00:31 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/20 16:51:38 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d_init(t_cub3d *cub)
{
	t_asset_manager	*am;

	ft_bzero(cub, sizeof(t_cub3d));
	am = &cub->am;
	// am->sprite_weapon = am_load_sprite(
	// 	cub->mlx,
	// 	(t_sprite){  }, "assets/sprites/weapons.png")
	return (1);
}
