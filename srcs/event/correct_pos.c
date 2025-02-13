/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:48:02 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/13 14:53:56 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Check four corners of the player imgage
 */
static int	is_collision(t_cub *c, int x, int32_t y)
{
	if (ft_is_valid_pos(c, x, y)
		|| ft_is_valid_pos(c, x + CELL_PX, y)
		|| ft_is_valid_pos(c, x, y + CELL_PX)
		|| ft_is_valid_pos(c, x + CELL_PX, y + CELL_PX)
	)
	{
		return (false);
	}
	return (true);
}

void	collision(t_cub *c)
{
	t_player	*player;

	player = &c->player;
}

static int	correct_x(t_cub *c, t_player *player, int x, int32_t y)
{
	const int32_t	row = y / CELL_PX;
	const int32_t	col = x / CELL_PX;

	if (player->current.x > x)
	{
		player->next.x = (col + 1) * CELL_PX;
	}
	else if (player->current.x < x)
	{
		player->next.x = (col + 1) * CELL_PX;
	}
}

static int	correct_y(t_cub *c, t_player *player, int x, int32_t y)
{
	
}

void	correct_pos(t_cub *c)
{
	t_player	*player;

	player = &c->player;
	if (is_collision(c, player->next.x, player->current.y))
		correct_x(c, player, player->next.x, player->current.y);
	if (is_collision(c, player->current.x, player->next.y))
		correct_y(c, player, player->next.x, player->current.y);
	if (is_collision(c, player->next.x, player->next.y))
	{
		correct_x(c, player, player->next.x, player->next.y);
		correct_y(c, player, player->next.x, player->next.y);
	}
}
