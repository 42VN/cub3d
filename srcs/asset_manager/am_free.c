/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:38:36 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/26 15:43:25 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	am_free_sprite(mlx_t *mlx, t_sprite *s)
{
	int	i;

	i = 0;
	if (s && s->frames)
	{
		while (s->frames[i])
		{
			mlx_delete_image(mlx, s->frames[i]);
			++i;
		}
		free(s);
	}
}

static void	am_free_walls(mlx_t *mlx, t_asset_manager *am)
{
	if (am->walls[0])
		mlx_delete_image(mlx, am->walls[0]);
	if (am->walls[1])
		mlx_delete_image(mlx, am->walls[1]);
	if (am->walls[2])
		mlx_delete_image(mlx, am->walls[2]);
	if (am->walls[3])
		mlx_delete_image(mlx, am->walls[3]);
}

static void	am_free_imgs(mlx_t *mlx, t_asset_manager *am)
{
	if (am->ceiling)
		mlx_delete_image(mlx, am->ceiling);
	if (am->floor)
		mlx_delete_image(mlx, am->floor);
	if (am->scene)
		mlx_delete_image(mlx, am->scene);
	if (am->player) 
		mlx_delete_image(mlx, am->player);
	if (am->door) 
		mlx_delete_image(mlx, am->door);
	if (am->m_door) 
		mlx_delete_image(mlx, am->m_door);
	if (am->m_map)
		mlx_delete_image(mlx, am->m_map);
	if (am->map)
		mlx_delete_image(mlx, am->map);
	if (am->m_map_bg)
		mlx_delete_image(mlx, am->m_map_bg);
	if (am->m_player)
		mlx_delete_image(mlx, am->m_player);
	if (am->m_space)
		mlx_delete_image(mlx, am->m_space);
	if (am->m_wall)
		mlx_delete_image(mlx, am->m_wall);
	am_free_walls(mlx, am);
}

void	am_free(mlx_t *mlx, t_asset_manager *am)
{
	if (am)
	{
		if (am->sprite_weapon)
			am_free_sprite(mlx, am->sprite_weapon);
		if (am->sprite_door)
			am_free_sprite(mlx, am->sprite_door);
		am_free_imgs(mlx, am);
	}
}
