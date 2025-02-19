/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:32:20 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/20 13:11:00 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	event_loop_handler(void *data)
{
	t_cub	*c;

	c = (t_cub *)data;
	inputs(c);
	collision(c);
    draw_map(c);
	draw_minimap(c);
}

