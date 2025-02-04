// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   start_cub.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/20 00:30:53 by hitran            #+#    #+#             */
// /*   Updated: 2025/01/29 11:00:00 by hitran           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3d.h"

// static void	move_player(t_cub *cub)
// {
// 	cub->current = cub->player.next;
// 	cub->m_images[PLAYER]->instances[0].x = cub->current.x * MPX;
// 	cub->m_images[PLAYER]->instances[0].y = cub->current.y * MPX;
// }
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
	t_cub		*cub;
	double		angle;
	// t_dpoint	cur;

	cub = (t_cub *)param;
	ray_casting(cub);
	// cur = cub->player.current;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_cub(cub, EXIT_SUCCESS);
	// else if (keydata.key == MLX_KEY_W)
	// 	cub->player.next.y = cur.y - 4;
	// else if (keydata.key == MLX_KEY_S)
	// 	cub->player.next.y = cur.y + 4;
	// else if (keydata.key == MLX_KEY_A)
	// 	cub->player.next = (t_point){cur.x - 1, cur.y, cur.rad};
	// else if (keydata.key == MLX_KEY_D)
	// 		cub->player.next = (t_point){cur.x + 1, cur.y, cur.rad};
	else if (keydata.key == MLX_KEY_LEFT)
		cub->player.angle = rescale(cub->player.angle + PI / 36);
	else if (keydata.key == MLX_KEY_RIGHT)
		cub->player.angle = rescale(cub->player.angle - PI / 36);
	else
		return ;
	// cub->player.angle = angle;
	// if (cub->map.grid[cub->player.next.y][cub->player.next.x] != '1')
	// 	move_player(cub);
}

static void	close_hook(void *param)
{
	exit_cub((t_cub *)param, EXIT_SUCCESS);
}

void	start_minimap(t_cub *cub)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "minimap", true);
	if (!cub->mlx)
		game_error(cub, mlx_strerror(mlx_errno));

	cub->rays = (t_ray *)ft_calloc(WIDTH, sizeof(t_ray));
	if (cub->rays == NULL)
		game_error(cub, strerror(errno));

	display_minimap(cub, -1, -1);
	mlx_key_hook(cub->mlx, key_hook, cub);
	mlx_close_hook(cub->mlx, close_hook, cub);
	mlx_loop(cub->mlx);
	exit_cub(cub, EXIT_SUCCESS);
}
