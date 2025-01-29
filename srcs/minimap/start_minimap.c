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

static double	new_angle(double current, double delta)
{
	double	new_angle;

	new_angle = current + delta;
	while (new_angle < 0)
		new_angle += 2 * PI;
	while (new_angle > 2* PI)
		new_angle -= 2 * PI;
	return (new_angle);
}

static void	move_player(t_cub3d *cub)
{
	cub->current = cub->next;
	cub->mini_images[PLAYER]->instances[0].x = cub->current.col * MPX;
	cub->mini_images[PLAYER]->instances[0].y = cub->current.row * MPX;
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			exit_cub3d(cub, EXIT_SUCCESS);
		else if (keydata.key == MLX_KEY_W)
			cub->next = (t_point){cub->current.row - 1, cub->current.col,
							cub->current.direction, cub->current.angle};
		else if (keydata.key == MLX_KEY_S)
			cub->next = (t_point){cub->current.row + 1, cub->current.col,
							cub->current.direction, cub->current.angle};
		else if (keydata.key == MLX_KEY_A)
			cub->next = (t_point){cub->current.row, cub->current.col - 1,
							cub->current.direction, new_angle(cub->current.angle, PI / 2)};
		else if (keydata.key == MLX_KEY_D)
			cub->next = (t_point){cub->current.row, cub->current.col + 1,
							cub->current.direction, new_angle(cub->current.angle, -PI / 2)};
		else if (keydata.key == MLX_KEY_LEFT)
			cub->next = (t_point){cub->current.row, cub->current.col,
							cub->current.direction, new_angle(cub->current.angle, PI / 10)};
		else if (keydata.key == MLX_KEY_RIGHT)
			cub->next = (t_point){cub->current.row, cub->current.col,
							cub->current.direction, new_angle(cub->current.angle, -PI / 10)};
		else
			return ;
		if (cub->map->arr[cub->next.row][cub->next.col] != '1')
			move_player(cub);
	}
}

static void	close_hook(void *param)
{
	exit_cub3d((t_cub3d *)param, EXIT_SUCCESS);
}

void	start_minimap(t_cub3d *cub)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	cub->mlx = mlx_init(cub->map->max_cols * MPX, cub->map->max_rows * MPX, "minimap", true);
	if (!cub->mlx)
		game_error(cub, mlx_strerror(mlx_errno));
	cub->current = cub->map->start;
	display_minimap(cub, -1, -1);
	mlx_key_hook(cub->mlx, key_hook, cub);
	mlx_close_hook(cub->mlx, close_hook, cub);
	mlx_loop(cub->mlx);
	exit_cub3d(cub, EXIT_SUCCESS);
}
