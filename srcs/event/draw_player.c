/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:13:34 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/20 23:54:28 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_cub *c)
{
	t_player *const	player = &c->player;
	t_sprite *const	player_sprite = c->am.sprite_weapon;

	ft_copy_pixels(\
		c->am.player, \
		player_sprite->frames[player_sprite->idx], \
		c->am.player->width, \
		c->am.player->height\
	);
}