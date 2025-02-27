/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:19:59 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/27 14:01:41 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Check four corners of the player imgage
 */
static int	is_collision(t_cub *c, int x, int32_t y)
{
	if (!ft_is_valid_pos(c, x, y)
		|| !ft_is_valid_pos(c, x + M_PLAYER_SIZE, y)
		|| !ft_is_valid_pos(c, x, y + M_PLAYER_SIZE)
		|| !ft_is_valid_pos(c, x + M_PLAYER_SIZE, y + M_PLAYER_SIZE)
	)
	{
		return (true);
	}
	return (false);
}

static void	correct_x(t_player *player, int x)
{
	const int32_t	col = x / CELL_PX;

	if (player->prev.x > x)
	{
		player->current.x = (col + 1) * CELL_PX;
	}
	else if (player->prev.x < x)
	{
		player->current.x = (col + 1) * CELL_PX - 1 - M_PLAYER_SIZE;
	}
}

static void	correct_y(t_player *player, int32_t y)
{
	const int32_t	row = y / CELL_PX;

	if (player->prev.y > player->current.y)
	{
		player->current.y = (row + 1) * CELL_PX;
	}
	else if (player->prev.y < player->current.y)
	{
		player->current.y = (row + 1) * CELL_PX - 1 - M_PLAYER_SIZE;
	}
}

void	collision(t_cub *c)
{
	t_player	*player;

	player = &c->player;
	if (is_collision(c, player->current.x, player->prev.y))
		correct_x(player, player->current.x);
	if (is_collision(c, player->prev.x, player->current.y))
		correct_y(player, player->current.y);
	if (is_collision(c, player->current.x, player->current.y))
	{
		correct_x(player, player->current.x);
		correct_y(player, player->current.y);
	}
}
