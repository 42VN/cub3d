/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:38:36 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/17 17:54:34 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_manager.h"

static void	am_free_sprite(mlx_t *mlx, t_sprite *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s->frames[i])
		{
			mlx_delete_image(mlx, s->frames[i]);
			++i;
		}
		free(s);
	}
}

void	am_free(mlx_t *mlx, t_asset_manager *am)
{
	if (am)
	{
		if (am->sprite_weapon)
		{
			am_free_sprite(mlx, am->sprite_weapon);
		}
		free(am);
	}
}