/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:38:48 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/21 14:26:02 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	animate_player(t_cub *c, double elapsed_time)
{
	t_sprite			*player;

	player = c->am.sprite_weapon;
	if (c->player.is_attacking == 0)
		return ;
	player->elapsed_time += elapsed_time;
	if (player->elapsed_time >= 0.099)
	{
		player->idx++;
		player->elapsed_time -= 0.099;
	}
	if (c->am.sprite_weapon->options.dir == DIR_HORIZONTAL)
	{
		if (player->idx == (int32_t)player->cols - 1)
		{
			player->idx = 0;
			player->elapsed_time = 0.0;
		}
	}
	else
	{
		if (player->idx == (int32_t)player->rows - 1)
		{
			player->idx = 0;
			player->elapsed_time = 0.0;
		}
	}
}

void	animate_door(t_cub *c, double elapsed_time)
{
	
}

void	animate(t_cub *c)
{
	double	elapsed_time;

	elapsed_time = c->mlx->delta_time;
}