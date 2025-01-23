/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_close_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:38:41 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/22 18:41:17 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	event_close_handler(void *data)
{
	t_cub3d	*c;

	c = (t_cub3d *)data;
	cub3d_free(c);
	exit(EXIT_SUCCESS);
}
