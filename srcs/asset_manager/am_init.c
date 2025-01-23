/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:28:06 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/22 19:59:51 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_manager.h"
#include "cub3d.h"

void	am_init(t_cub3d *c)
{
	t_asset_manager	*am;

	am = &c->am;
	am->sprite_weapon = am_load_sprite(c->mlx, (t_sprite_options){1, 6, DIR_VERTICAL}, "assets/sprites/weapons.png");
	am->ceiling = mlx_new_image(c->mlx, WIDTH, HEIGHT / 2); 
	am->floor = mlx_new_image(c->mlx, WIDTH, HEIGHT / 2); 
	ft_fill_color(am->ceiling, (t_color){245,214,34,255});
	ft_fill_color(am->floor, (t_color){222,194,30,255});
}
