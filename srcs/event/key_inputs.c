/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:27:43 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/27 09:27:41 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_dpoint	next_point(t_dpoint cur, double angle, keys_t key)
{
	t_dpoint	next;

	next = (t_dpoint){cur.x, cur.y};
	if (key == MLX_KEY_W)
	{
		next = (t_dpoint){cur.x + cos(angle), cur.y - sin(angle)};
	}
	else if (key == MLX_KEY_S)
		next = (t_dpoint){cur.x - cos(angle), cur.y + sin(angle)};
	else if (key == MLX_KEY_A)
		next = (t_dpoint){cur.x + cos(angle + PI / 2),
						cur.y - sin(angle + PI / 2)};
	else if (key == MLX_KEY_D)
		next = (t_dpoint){cur.x + cos(angle + 3 * PI / 2),
						cur.y - sin(angle + 3 * PI / 2)};
	return (next);
}

void key_inputs(t_cub *c)
{
	t_dpoint	cur;

	cur = c->player.current;
	c->player.prev =  c->player.current;
	if (mlx_is_key_down(c->mlx, MLX_KEY_ESCAPE))
		cub3d_exit(c, EXIT_SUCCESS);
	if (mlx_is_key_down(c->mlx, MLX_KEY_W))
	{
		c->player.current = next_point(cur, c->player.angle, MLX_KEY_W);
	}
	if (mlx_is_key_down(c->mlx, MLX_KEY_S))
		c->player.current = next_point(cur, c->player.angle, MLX_KEY_S);
	if (mlx_is_key_down(c->mlx, MLX_KEY_A))
		c->player.current = next_point(cur, c->player.angle, MLX_KEY_A);
	if (mlx_is_key_down(c->mlx, MLX_KEY_D))
		c->player.current = next_point(cur, c->player.angle, MLX_KEY_D);
	if (mlx_is_key_down(c->mlx, MLX_KEY_LEFT))
		c->player.angle = rescale(c->player.angle + PI / 36);
	if (mlx_is_key_down(c->mlx, MLX_KEY_RIGHT))
		c->player.angle = rescale(c->player.angle - PI / 36);
}
