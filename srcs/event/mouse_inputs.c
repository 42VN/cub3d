/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:28:32 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/27 15:04:23 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mouse_move_inputs(t_cub *c)
{
	int32_t	last_x;

	last_x = c->mouse_x;
	mlx_get_mouse_pos(c->mlx, &c->mouse_x, &c->mouse_y);
	if (last_x < c->mouse_x)
		c->player.angle = rescale(c->player.angle - PI / 36);
	if (last_x > c->mouse_x)
		c->player.angle = rescale(c->player.angle + PI / 36);
}

static void	mouse_press_inputs(t_cub *c)
{
	double	elapsed_time;

	elapsed_time = c->mlx->delta_time;
	if (mlx_is_mouse_down(c->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		c->player.is_attacking = 1;
		animate_player(c, c->am.sprite_weapon, elapsed_time);
	}
	else
	{
		c->player.is_attacking = 0;
		c->am.sprite_weapon->idx = 0;
	}
}

void	mouse_inputs(t_cub *c)
{
	mouse_move_inputs(c);
	mouse_press_inputs(c);
}
