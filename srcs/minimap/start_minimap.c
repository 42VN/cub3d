/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:30:53 by hitran            #+#    #+#             */
/*   Updated: 2025/01/29 11:00:00 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	update_radian(double current, double delta)
{
	double	res;

	res = current + delta;
	while (res < 0)
		res += 2 * PI;
	while (res >= 2* PI)
		res -= 2 * PI;
	return (res);
}

static void	move_player(t_cub3d *cub)
{
	cub->current = cub->next;
	cub->m_images[PLAYER]->instances[0].x = cub->current.x * MPX;
	cub->m_images[PLAYER]->instances[0].y = cub->current.y * MPX;
}
/*
		NO
	WE		EA
		SO

		W
	A	S	D

	NO

	WE+W = NO+A
	WE+S = NO+D
	WE+A = NO+S
	WE+D = NO+W

	SO+W = NO+S
	SO+S = NO+W
	SO+A = NO+D
	SO+D = NO+A

	EA+W = NO+D
	EA+S = NO+A
	EA+A = NO+W
	EA+D = NO+S
*/

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub;
	t_point	cur;

	cub = (t_cub3d *)param;
	cur = cub->current;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_cub3d(cub, EXIT_SUCCESS);
	else if (keydata.key == MLX_KEY_W)
		cub->next = (t_point){cur.x, cur.y - 1, cur.rad};
	else if (keydata.key == MLX_KEY_S)
		cub->next = (t_point){cur.x, cur.y + 1, cur.rad};
	else if (keydata.key == MLX_KEY_A)
		cub->next = (t_point){cur.x - 1, cur.y, cur.rad};
	else if (keydata.key == MLX_KEY_D)
			cub->next = (t_point){cur.x + 1, cur.y, cur.rad};
	else if (keydata.key == MLX_KEY_LEFT)
		cub->next = (t_point){cur.x, cur.y, update_radian(cur.rad, PI / 10)};
	else if (keydata.key == MLX_KEY_RIGHT)
		cub->next = (t_point){cur.x, cur.y, update_radian(cur.rad, -PI / 10)};
	else
		return ;
	if (cub->map->grid[cub->next.y][cub->next.x] != '1')
		move_player(cub);
}

static void	close_hook(void *param)
{
	exit_cub3d((t_cub3d *)param, EXIT_SUCCESS);
}

void	start_minimap(t_cub3d *cub)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	cub->mlx = mlx_init(cub->map->max_cols * MPX, cub->map->max_rows * MPX,
					"minimap", true);
	if (!cub->mlx)
		game_error(cub, mlx_strerror(mlx_errno));
	cub->current = cub->map->start;
	display_minimap(cub, -1, -1);
	mlx_key_hook(cub->mlx, key_hook, cub);
	mlx_close_hook(cub->mlx, close_hook, cub);
	mlx_loop(cub->mlx);
	exit_cub3d(cub, EXIT_SUCCESS);
}
