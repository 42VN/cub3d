/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:38:48 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/27 14:36:18 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	animate_player(t_cub *c, t_sprite *player, double elapsed_time)
{
	if (!c->player.is_attacking)
		return ;
	player->elapsed_time += elapsed_time;
	if (player->elapsed_time >= 0.099)
	{
		player->idx++;
		player->elapsed_time -= 0.099;
	}
	if (c->am.sprite_weapon->options.dir == DIR_HORIZONTAL)
	{
		if (player->idx >= player->cols)
		{
			player->idx = 0;
			c->player.is_attacking = 0;
		}
	}
	else
	{
		if (player->idx >= player->rows)
		{
			player->idx = 0;
			c->player.is_attacking = 0;
		}
	}
}
