/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:28:32 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/20 13:35:01 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// static void mouse_move_inputs(t_cub *c)
// {
// 	int32_t	last_x;
// 	double	angle;

// 	last_x = c->mouse_x;
// 	mlx_get_mouse_pos(c->mlx, &c->mouse_x, &c->mouse_y);
// 	if (last_x < cub3d->mouse_x)
// 		angle -= PI / 36;
// 	if (last_x > cub3d->mouse_x)
// 		angle += PI / 36;
// 	if (angle < 0)
// 		angle += 2 * PI;
// 	if (angle >= 2 * PI)
// 		angle -= 2 * PI;
// 	c->player.angle = angle;
// }

static void mouse_move_inputs(t_cub *c)
{
	int32_t	last_x;

	last_x = c->mouse_x;
	mlx_get_mouse_pos(c->mlx, &c->mouse_x, &c->mouse_y);
	if (last_x < c->mouse_x)
		c->player.angle = rescale(c->player.angle - PI / 36);
	if (last_x > c->mouse_x)
		c->player.angle = rescale(c->player.angle + PI / 36);
}

static void mouse_press_inputs(t_cub *c)
{
	
}


void mouse_inputs(t_cub *c)
{
    mouse_move_inputs(c);
	mouse_press_inputs(c);
}