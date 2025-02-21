/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:32:20 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/21 13:52:21 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	draw(t_cub *c)
{
	draw_map(c);
	draw_minimap(c);
	draw_player(c);
	draw_scene(c);
}


void	event_loop_handler(void *data)
{
	t_cub	*c;

	c = (t_cub *)data;
	inputs(c);
	collision(c);
	ray_casting(c);
    draw(c);
}

