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

static void	hook_init(t_cub *c)
{
	if (!mlx_loop_hook(c->mlx, event_loop_handler, c))
	{
		cub3d_error_exit(c, "cub3d_init: mlx_loop_hook");
	}
	mlx_close_hook(c->mlx, event_close_handler, c);
}

void	cub3d_init(t_cub *c)
{
	t_asset_manager	*am;

	ft_bzero(c, sizeof(t_cub));
	am = &c->am;
	c->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!c->mlx)
	{
		cub3d_error_exit(c, "cub3d_init: mlx_init");
	}
	mlx_get_mouse_pos(c->mlx, &c->mouse_x, &c->mouse_y);
	am_init(c);
	hook_init(c);
	cub3d_render(c);
}
