/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:00:31 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 10:51:47 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d_init(t_cub *cub)
{
	t_asset_manager	*am;

	ft_bzero(cub, sizeof(t_cub));
	am = &cub->am;
	// am->sprite_weapon = am_load_sprite(
	// 	cub->mlx,
	// 	(t_sprite){  }, "assets/sprites/weapons.png")
	return (1);
}
